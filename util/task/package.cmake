find_program(CONAN_EXE NAMES "conan" DOC "Path to Conan package manager tool.")
find_program(CTEST_EXE NAMES "ctest" DOC "Path to CTest test runner.")
find_program(CPACK_EXE NAMES "cpack" DOC "Path to CPack packaging tool.")

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

if (NOT CPACK_EXE)
    message(SEND_ERROR
        "CPack executable not found on system - this is required to package the project."
    )
endif()

if (NOT CONAN_EXE OR NOT CTEST_EXE OR NOT CPACK_EXE)
    message(FATAL_ERROR
        "Not all programs required to run script are available on system - please check which programs are missing above."
    )
endif()

set(BUILT_DIR built/Release)
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
if (CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    execute_process(COMMAND ${CPACK_EXE} -G "DEB" WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
    execute_process(COMMAND ${CPACK_EXE} -G "ZIP" --config CPackSourceConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    execute_process(COMMAND ${CPACK_EXE} -G "NSIS" WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
    execute_process(COMMAND ${CPACK_EXE} -G "ZIP" --config CPackSourceConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin")
    execute_process(COMMAND ${CPACK_EXE} -G "DMG" WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
    execute_process(COMMAND ${CPACK_EXE} -G "ZIP" --config CPackSourceConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
else()
    execute_process(COMMAND ${CPACK_EXE} WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
    execute_process(COMMAND ${CPACK_EXE} --config CPackSourceConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
endif()
