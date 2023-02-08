set(BINARY_NAME sb64)

add_library(${BINARY_NAME}
    src/detail/to_alphabet_char.cpp
    src/detail/to_original_char.cpp
    src/decode_b64.cpp
    src/is_valid_b64.cpp
    src/Letter.cpp
    src/to_b64.cpp

    inc/${BINARY_NAME}/detail/to_alphabet_char.h
    inc/${BINARY_NAME}/detail/to_original_char.h
    inc/${BINARY_NAME}/detail/constant/alphabet.h
    inc/${BINARY_NAME}/detail/utility/iterable_reader.h
    inc/${BINARY_NAME}/detail/utility/write_stream.h
    inc/${BINARY_NAME}/constant/common.h
    inc/${BINARY_NAME}/decode_b64.h
    inc/${BINARY_NAME}/is_valid_b64.h
    inc/${BINARY_NAME}/Letter.h
    inc/${BINARY_NAME}/to_b64.h
)

install(TARGETS ${BINARY_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES
    inc/${BINARY_NAME}/constant/common.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${BINARY_NAME}/constant
)
install(FILES
    inc/${BINARY_NAME}/decode_b64.h
    inc/${BINARY_NAME}/is_valid_b64.h
    inc/${BINARY_NAME}/Letter.h
    inc/${BINARY_NAME}/to_b64.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${BINARY_NAME}
)

setupFlags(${BINARY_NAME})
target_include_directories(${BINARY_NAME} PUBLIC inc)
