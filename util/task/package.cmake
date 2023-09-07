find_program(CONAN_EXE NAMES "conan" DOC "Path to Conan package manager tool.")
if (NOT CONAN_EXE)
    message(FATAL_ERROR 
        "Conan package manager executable not found on system - this is required to get dependencies for the project."
    )
endif()

find_program(CTEST_EXE NAMES "ctest" DOC "Path to CTest test runner.")
if (NOT CTEST_EXE)
    message(FATAL_ERROR 
        "CTest test runner executable not found on system - this is required to run the project's tests."
    )
endif()

set(BUILT_DIR built/single)
set(RELEASE_PRESET release)

message(STATUS "Run Conan...")
file(MAKE_DIRECTORY ${BUILT_DIR})
execute_process(COMMAND ${CONAN_EXE} install . --build=missing COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Configure CMake project...")
execute_process(COMMAND ${CMAKE_COMMAND} --preset ${RELEASE_PRESET} COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Build and test in release mode...")
execute_process(COMMAND ${CMAKE_COMMAND} --build --preset ${RELEASE_PRESET} COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CTEST_EXE} --preset ${RELEASE_PRESET} COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Package project...")
execute_process(COMMAND ${CMAKE_COMMAND} --build --target package --preset ${RELEASE_PRESET} COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CMAKE_COMMAND} --build --target package_source --preset ${RELEASE_PRESET} COMMAND_ERROR_IS_FATAL ANY)
