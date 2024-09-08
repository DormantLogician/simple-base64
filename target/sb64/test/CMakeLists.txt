set(BINARY_NAME sb64)
set(MODULE_NAME all_${BINARY_NAME}_specs)

makeTest(${MODULE_NAME} ${MODULE_NAME}.cpp)

add_subdirectory(specs_decode_b64)
add_subdirectory(specs_is_valid_b64)
add_subdirectory(specs_iterable_reader)
add_subdirectory(specs_Letter)
add_subdirectory(specs_Letter_as_uchars)
add_subdirectory(specs_Letter_bits)
add_subdirectory(specs_Letter_by_eight_bits)
add_subdirectory(specs_Letter_by_six_bits)
add_subdirectory(specs_Letter_to_uchar)
add_subdirectory(specs_to_alphabet_char)
add_subdirectory(specs_to_b64)
add_subdirectory(specs_to_original_char)
add_subdirectory(specs_write_stream)

target_link_libraries(${MODULE_NAME} PRIVATE ${BINARY_NAME}
    ${BINARY_NAME}_specs_decode_b64
    ${BINARY_NAME}_specs_is_valid_b64
    ${BINARY_NAME}_specs_iterable_reader
    ${BINARY_NAME}_specs_Letter
    ${BINARY_NAME}_specs_Letter_as_uchars
    ${BINARY_NAME}_specs_Letter_bits
    ${BINARY_NAME}_specs_Letter_by_eight_bits
    ${BINARY_NAME}_specs_Letter_by_six_bits
    ${BINARY_NAME}_specs_Letter_to_uchar
    ${BINARY_NAME}_specs_to_alphabet_char
    ${BINARY_NAME}_specs_to_b64
    ${BINARY_NAME}_specs_to_original_char
    ${BINARY_NAME}_specs_write_stream
)
