find_program(CTEST_EXE NAMES "ctest" DOC "Path to CTest test runner.")
find_program(CPACK_EXE NAMES "cpack" DOC "Path to CPack packaging tool.")

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

if (NOT CTEST_EXE OR NOT CPACK_EXE)
    message(FATAL_ERROR
        "Not all programs required to run script are available on system - please check which programs are missing above."
    )
endif()

set(BUILT_DIR built)

message(STATUS "Build and test in release mode...")
execute_process(COMMAND ${CMAKE_COMMAND} --build --preset conan-release --config Release COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CTEST_EXE} --preset conan-release -C Release COMMAND_ERROR_IS_FATAL ANY)

message(STATUS "Package project...")
if (CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    execute_process(COMMAND ${CPACK_EXE} -G "DEB" --config Release/CPackConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
    execute_process(COMMAND ${CPACK_EXE} -G "ZIP" --config Release/CPackSourceConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    execute_process(COMMAND ${CPACK_EXE} -G "NSIS" --config Release/CPackConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
    execute_process(COMMAND ${CPACK_EXE} -G "ZIP" --config Release/CPackSourceConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin")
    execute_process(COMMAND ${CPACK_EXE} -G "DragNDrop" --config Release/CPackConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
    execute_process(COMMAND ${CPACK_EXE} -G "ZIP" --config Release/CPackSourceConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
else()
    execute_process(COMMAND ${CPACK_EXE} --config Release/CPackConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
    execute_process(COMMAND ${CPACK_EXE} --config Release/CPackConfig.cmake WORKING_DIRECTORY ${BUILT_DIR} COMMAND_ERROR_IS_FATAL ANY)
endif()

