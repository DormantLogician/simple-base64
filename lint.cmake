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

find_program(CLANG_TIDY_EXE NAMES "clang-tidy" DOC "Path to clang-tidy static analysis tool.")
if (NOT CLANG_TIDY_EXE)
    message(FATAL_ERROR 
        "Clang-tidy executable not found on system - this is required in order to lint the project's code."
    )
endif()


set(BUILT_DIR built)
set(RELEASE_PRESET release)
set(DEBUG_PRESET debug)
set(TEST_PRESET test)

message(STATUS "Running Conan...")
execute_process(COMMAND ${CONAN_EXE} install .. WORKING_DIRECTORY ${BUILT_DIR} OUTPUT_QUIET COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Build and test with Clang-Tidy...")
execute_process(COMMAND ${CMAKE_COMMAND}  -DSTRICT_CLANG_TIDY=ON --preset ${RELEASE_PRESET} OUTPUT_QUIET COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CMAKE_COMMAND} --build --preset ${RELEASE_PRESET} COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CTEST_EXE} --preset ${RELEASE_PRESET} COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Build and test with Sanitizers...")
execute_process(COMMAND ${CMAKE_COMMAND} --preset ${TEST_PRESET} OUTPUT_QUIET COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CMAKE_COMMAND} --build --preset ${TEST_PRESET} OUTPUT_QUIET COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CTEST_EXE} --preset ${TEST_PRESET} COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Build and test with Valgrind/Purify...")
execute_process(COMMAND ${CMAKE_COMMAND} --preset ${DEBUG_PRESET} OUTPUT_QUIET COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CMAKE_COMMAND} --build --preset ${DEBUG_PRESET} OUTPUT_QUIET COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CTEST_EXE} -D MemoryCheck WORKING_DIRECTORY ${BUILT_DIR})
