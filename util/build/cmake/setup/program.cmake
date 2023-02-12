find_program(CLANG_TIDY_EXE NAMES "clang-tidy" DOC "Path to clang-tidy static analysis tool.")
if (NOT CLANG_TIDY_EXE)
    message(WARNING 
        "Clang-tidy executable not found on system - linting will not be available."
    )
else()
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE} -p ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json)
endif()
