cmake_minimum_required(VERSION 3.16)

project(cpu_monitor C)

set(CMAKE_C_COMPILER "clang")
# 设置C标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 查找所需的包
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBBPF REQUIRED libbpf)

# 设置BPF相关变量
set(CLANG_OPTIONS "-g -O0 -target bpf")
set(BPFTOOL "bpftool")

# 生成BPF对象文件
add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/monitor.bpf.o
        COMMAND clang -g -O0 -target bpf -D__TARGET_ARCH_x86_64 -I/usr/include/x86_64-linux-gnu -I. -c ${CMAKE_CURRENT_SOURCE_DIR}/src/monitor.bpf.c -o ${CMAKE_CURRENT_BINARY_DIR}/monitor.bpf.o
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/monitor.bpf.c
        COMMENT "Compiling BPF program"
)

# 生成BPF骨架头文件
add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/monitor.skel.h
        COMMAND ${BPFTOOL} gen skeleton ${CMAKE_CURRENT_BINARY_DIR}/monitor.bpf.o > ${CMAKE_CURRENT_BINARY_DIR}/monitor.skel.h
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/monitor.bpf.o
        COMMENT "Generating BPF skeleton header"
)

# 添加可执行文件
add_executable(cpu_monitor
        src/main.c
        src/vmlinux.h
        src/monitor.bpf.c
        src/monitor.h
        src/cpu_calculator.c
        src/cpu_calculator.h
        src/cgroup_config.h
        src/cgroup_config.c
        src/cgroup_adjuster.c
)

# 设置包含目录
target_include_directories(cpu_monitor PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_BINARY_DIR}
        ${LIBBPF_INCLUDE_DIRS}
)

# 链接所需的库
target_link_libraries(cpu_monitor PRIVATE
        ${LIBBPF_LIBRARIES}
        pthread
        elf
)

# 安装目标
install(TARGETS cpu_monitor
        RUNTIME DESTINATION bin
)