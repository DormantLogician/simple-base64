include(CTest) # Enable testing.

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CODEBLOCKS_EXCLUDE_EXTERNAL_FILES ON) # Filter out external files in CodeBlocks IDE.

option(BUILD_SHARED_LIBS "Build shared libraries instead of linking statically" OFF)

set(CMAKE_BUILD_PARALLEL_LEVEL 4)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Allow clang-tidy to access compile commands so linting is possible.
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR}) # Allow CMake to find Conan's packages.

set(CMAKE_CONFIGURATION_TYPES Debug Release RelWithDebInfo MinSizeRel Test Valgrind Profile)
