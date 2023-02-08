set(SUITE_NAME ${BINARY_NAME}_specs_is_valid_b64)

add_library(${SUITE_NAME} OBJECT
    specs_is_valid_b64.cpp
    inc/specs_is_valid_b64/string_is_valid_b64.h
)

target_sources(${SUITE_NAME} PRIVATE
    src/string_is_valid_b64.cpp
)

target_link_libraries(${SUITE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)
target_include_directories(${SUITE_NAME} PRIVATE inc)

setupFlags(${SUITE_NAME})
