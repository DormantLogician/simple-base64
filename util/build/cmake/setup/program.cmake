find_program(CLANG_TIDY_EXE NAMES "clang-tidy" DOC "Path to clang-tidy static analysis tool.")
if (NOT CLANG_TIDY_EXE)
    message(WARNING 
        "Clang-tidy executable not found on system - linting will be disabled for for Makefile and Ninja generators."
    )
else()
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE} -p ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json)
endif()


# Find Valgrind for use with CTest.
find_program(VALGRIND_EXE NAMES "valgrind" DOC "Path to valgrind dynamic analysis tool.")
if (NOT VALGRIND_EXE)
    message(WARNING 
        "Valgrind executable not found on system - Valgrind CMake configuration will not be usable."
    )
endif()
