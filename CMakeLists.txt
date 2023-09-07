cmake_minimum_required(VERSION 3.21)

project(sb64
    LANGUAGES CXX
    DESCRIPTION "Simple base 64 encoder/decoder library."
    VERSION 1.0
)

set(SETUP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/util/build/cmake/setup) # Directory used by this CMake configuartion for setup-related includes.

include(${SETUP_DIR}/setup.cmake) # Perform general configuration related to project before continuing.
include(${SETUP_DIR}/common.cmake) # Define functions that are used later.
include(${SETUP_DIR}/dep.cmake)
include(${SETUP_DIR}/program.cmake) # Deps not included in linting because they are retrieved above.
include(${SETUP_DIR}/packing.cmake) # Configure CPack so we can package our binaries and sources.

# Add project's targets to build.
set(TARGET_DIR ${CMAKE_CURRENT_SOURCE_DIR}/target)

add_subdirectory(${TARGET_DIR}/sb64)

install(FILES LICENSE.txt DESTINATION ${CMAKE_INSTALL_DOCDIR})

# Enable binary and source packaging targets (for certain generators).
include(CPack)
