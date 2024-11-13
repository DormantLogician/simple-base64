# Disable reporting of 'possible' leaks, since they are usually false-positives.
set(VALGRIND_COMMAND_OPTIONS "--log-fd=2 --track-origins=yes --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=50 --show-leak-kinds=definite")

include(CTest) # Enable testing.

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CODEBLOCKS_EXCLUDE_EXTERNAL_FILES ON) # Filter out external files in CodeBlocks IDE.

set(CMAKE_BUILD_PARALLEL_LEVEL 4)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Allow clang-tidy to access compile commands so linting is possible.


