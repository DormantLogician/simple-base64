set(SUITE_NAME specs_unitname_fn)
set(SUITE_TARGET ${BINARY_NAME}_${SUITE_NAME})

add_library(${SUITE_TARGET} OBJECT
    ${SUITE_NAME}.cpp
)

target_link_libraries(${SUITE_TARGET} PRIVATE ${BINARY_NAME} ${TESTING_FRAMEWORK_TARGET})

setupFlags(${SUITE_TARGET})

target_link_libraries(${TEST_MODULE_TARGET} PRIVATE
    ${SUITE_TARGET}
)
