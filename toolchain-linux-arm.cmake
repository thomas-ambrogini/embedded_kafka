# Path of the cross compiler: /opt/cross-compilers/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER aarch64-none-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-none-linux-gnu-g++)

# where is the target environment located
set(CMAKE_FIND_ROOT_PATH  /opt/cross-compilers/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/)