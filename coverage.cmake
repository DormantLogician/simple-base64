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


set(BUILT_DIR built)
set(MULTI_PRESET multi)

message(STATUS "Run Conan...")
file(MAKE_DIRECTORY ${BUILT_DIR}/${MULTI_PRESET})
execute_process(COMMAND ${CONAN_EXE} install ../.. WORKING_DIRECTORY ${BUILT_DIR}/${MULTI_PRESET} OUTPUT_QUIET COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Configure CMake project...")
execute_process(COMMAND ${CMAKE_COMMAND} --preset ${MULTI_PRESET} OUTPUT_QUIET COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Build and test with code coverage...")
execute_process(COMMAND ${CMAKE_COMMAND} --build --preset ${MULTI_PRESET} --config Coverage COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CTEST_EXE} --preset ${MULTI_PRESET} -C Coverage COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CTEST_EXE} -C Coverage -M Experimental -T Coverage WORKING_DIRECTORY ${BUILT_DIR}/${MULTI_PRESET})
