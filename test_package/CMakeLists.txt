cmake_minimum_required(VERSION 3.21)

project(SB64ConanPackageTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BINARY_NAME sb64_conan_package_test)

add_executable(${BINARY_NAME}
    ${BINARY_NAME}.cpp
)

find_package(sb64 REQUIRED)
target_link_libraries(${BINARY_NAME} PRIVATE sb64::sb64)
