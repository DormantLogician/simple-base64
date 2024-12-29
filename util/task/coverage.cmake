find_program(CONAN_EXE NAMES "conan" DOC "Path to Conan package manager tool.")
find_program(CTEST_EXE NAMES "ctest" DOC "Path to CTest test runner.")

if (NOT CONAN_EXE)
    message(SEND_ERROR 
        "Conan package manager executable not found on system - this is required to get dependencies for the project."
    )
endif()

if (NOT CTEST_EXE)
    message(SEND_ERROR 
        "CTest test runner executable not found on system - this is required to run the project's tests."
    )
endif()

if (NOT CONAN_EXE OR NOT CTEST_EXE)
    message(FATAL_ERROR 
        "Not all programs required to run script are available on system - please check which programs are missing above."
    )
endif()

set(BUILT_DIR built)

message(STATUS "Run Conan...")
file(MAKE_DIRECTORY ${BUILT_DIR})
execute_process(COMMAND ${CONAN_EXE} install . --build=missing -s build_type=Release COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Configure CMake project...")
execute_process(COMMAND ${CMAKE_COMMAND} --preset conan-default COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Build and test with code coverage...")
execute_process(COMMAND ${CMAKE_COMMAND} --build --preset conan-release --config Release COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CTEST_EXE} --preset conan-release -C Release COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CTEST_EXE} -C Release -M Experimental -T Coverage WORKING_DIRECTORY ${BUILT_DIR})
