set(BINARY_NAME sb64)
set(MODULE_NAME all_${BINARY_NAME}_specs)
set(TESTING_FRAMEWORK_TARGET Boost::unit_test_framework)

makeTest(${MODULE_NAME} main.cpp)
target_sources(${MODULE_NAME} PRIVATE
    specs_decode_b64/specs_decode_b64.cpp
    specs_decode_b64/inc/testing_sb64/decode_to_uchars.h
    specs_decode_b64/src/decode_to_uchars.cpp
    specs_is_valid_b64/specs_is_valid_b64.cpp
    specs_is_valid_b64/inc/specs_is_valid_b64/string_is_valid_b64.h
    specs_is_valid_b64/src/string_is_valid_b64.cpp
    specs_iterable_reader.cpp
    specs_Letter.cpp
    specs_Letter_as_uchars.cpp
    specs_Letter_bits.cpp
    specs_Letter_by_eight_bits.cpp
    specs_Letter_by_six_bits.cpp
    specs_Letter_to_uchar.cpp
    specs_to_alphabet_char.cpp
    specs_to_b64/specs_to_b64.cpp
    specs_to_b64/inc/specs_to_b64/encode_to_uchars.h
    specs_to_b64/src/encode_to_uchars.cpp
    specs_to_original_char.cpp
    specs_write_stream/specs_write_stream.cpp
    specs_write_stream/inc/specs_write_stream/TestFixture.h
    specs_write_stream/src/TestFixture.cpp
)

target_include_directories(${MODULE_NAME} PRIVATE
    specs_decode_b64/inc
    specs_is_valid_b64/inc
    specs_to_b64/inc
    specs_write_stream/inc
)

add_custom_command(
    TARGET ${MODULE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        "$<TARGET_FILE:${BINARY_NAME}>"
        "${CMAKE_CURRENT_BINARY_DIR}"
)

target_link_libraries(${MODULE_NAME} PRIVATE ${BINARY_NAME} ${TESTING_FRAMEWORK_TARGET})
