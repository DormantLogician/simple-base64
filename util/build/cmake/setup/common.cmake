function(addTestDir TEST_DIR)
    if (BUILD_TESTING)
        add_subdirectory(${TEST_DIR})
    endif()
endfunction()

# Set up a new test with a name and associated source file.
function(makeTest TEST_NAME TEST_SOURCE)
    if (BUILD_TESTING)
        add_executable(${TEST_NAME} ${TEST_SOURCE})

        add_test(
            NAME ${TEST_NAME}
            COMMAND $<TARGET_FILE:${TEST_NAME}>
        )
    endif()
endfunction()

function(findDependency TARG_NAME)
    find_package(${TARG_NAME} REQUIRED)
    include_directories(${${TARG_NAME}_INCLUDE_DIRS})
endfunction()
