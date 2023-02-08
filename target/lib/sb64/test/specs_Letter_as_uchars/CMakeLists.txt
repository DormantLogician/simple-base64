set(SUITE_NAME ${BINARY_NAME}_specs_Letter_as_uchars)

add_library(${SUITE_NAME} OBJECT
    specs_Letter_as_uchars.cpp
)

target_link_libraries(${SUITE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)

setupFlags(${SUITE_NAME})
