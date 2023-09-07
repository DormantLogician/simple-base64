include(CTest) # Enable testing.

set(CMAKE_CODEBLOCKS_EXCLUDE_EXTERNAL_FILES ON) # Filter out external files in CodeBlocks IDE.

set(CMAKE_BUILD_PARALLEL_LEVEL 4)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Allow clang-tidy to access compile commands so linting is possible.

set(CMAKE_CONFIGURATION_TYPES Debug Release RelWithDebInfo MinSizeRel Test Profile Coverage)
