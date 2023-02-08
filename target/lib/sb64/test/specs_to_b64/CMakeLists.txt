set(SUITE_NAME ${BINARY_NAME}_specs_to_b64)

add_library(${SUITE_NAME} OBJECT
    specs_to_b64.cpp
    inc/specs_to_b64/encode_to_uchars.h
)

target_sources(${SUITE_NAME} PRIVATE
    src/encode_to_uchars.cpp
)

target_link_libraries(${SUITE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)
target_include_directories(${SUITE_NAME} PRIVATE inc)

setupFlags(${SUITE_NAME})
