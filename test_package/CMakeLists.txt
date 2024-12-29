cmake_minimum_required(VERSION 3.21)

project(ConanPackageTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(sb64 CONFIG REQUIRED)

get_property(SB64_DLL TARGET sb64::sb64 PROPERTY IMPORTED_LOCATION_RELEASE)
file(COPY ${SB64_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(BINARY_NAME conan_package_test)

add_executable(${BINARY_NAME}
    ${BINARY_NAME}.cpp
)

target_link_libraries(${BINARY_NAME} PRIVATE sb64::sb64)
