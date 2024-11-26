cmake_minimum_required(VERSION 3.10)

project("Easy IOT")

set(CMAKE_CXX_STANDARD 17)

#Set vcpkg cmake files
set(CMAKE_TOOLCHAIN_FILE "/home/keyzarrasya/Documents/cpp/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

add_executable(main main.cpp)

#Set the path of vcpkg include folder
target_include_directories(main PRIVATE /home/keyzarrasya/Documents/cpp/vcpkg/installed/x64-linux/include)
