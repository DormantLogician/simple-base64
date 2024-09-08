set(SUITE_NAME ${BINARY_NAME}_specs_to_original_char)

add_library(${SUITE_NAME} OBJECT
    specs_to_original_char.cpp
)

target_link_libraries(${SUITE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)

setupFlags(${SUITE_NAME})
