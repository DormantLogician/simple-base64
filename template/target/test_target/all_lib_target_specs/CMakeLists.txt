set(BINARY_NAME lib_target)
set(TEST_MODULE_TARGET all_${BINARY_NAME}_specs)
set(TESTING_FRAMEWORK_TARGET Boost::unit_test_framework)

makeTest(${TEST_MODULE_TARGET} ${TEST_MODULE_TARGET}.cpp)

add_subdirectory(fn/specs_unitname_fn)
