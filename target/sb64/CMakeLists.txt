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
    inc/${BINARY_NAME}/detail/constant/common.h
    inc/${BINARY_NAME}/detail/utility/iterable_reader.h
    inc/${BINARY_NAME}/detail/utility/write_stream.h
    inc/${BINARY_NAME}/decode_b64.h
    inc/${BINARY_NAME}/is_valid_b64.h
    inc/${BINARY_NAME}/Letter.h
    inc/${BINARY_NAME}/to_b64.h
)

generate_export_header(${BINARY_NAME}
    EXPORT_FILE_NAME ${BINARY_NAME}_def_exports.h
    EXPORT_MACRO_NAME ${BINARY_NAME}_EXPORT
)

configure_file(${PROJECT_SOURCE_DIR}/util/build/cmake/template/lib_export.h.in ${BINARY_NAME}_export.h)

set_target_properties(${BINARY_NAME} PROPERTIES PUBLIC_HEADER
     "inc/${BINARY_NAME}/decode_b64.h;inc/${BINARY_NAME}/is_valid_b64.h;inc/${BINARY_NAME}/Letter.h;inc/${BINARY_NAME}/to_b64.h;${CMAKE_CURRENT_BINARY_DIR}/${BINARY_NAME}_def_exports.h;${CMAKE_CURRENT_BINARY_DIR}/${BINARY_NAME}_export.h"
)

set_target_properties(${BINARY_NAME}
    PROPERTIES SOVERSION ${SB64_DEBIAN_SOVERSION}
)

install(TARGETS ${BINARY_NAME}
    EXPORT ${BINARY_NAME}Config
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${BINARY_NAME}
)

export(TARGETS ${BINARY_NAME}
    NAMESPACE ${BINARY_NAME}::
    FILE "${CMAKE_CURRENT_BINARY_DIR}/${BINARY_NAME}Config.cmake"
)

install(EXPORT ${BINARY_NAME}Config
    DESTINATION "pkg/cmake"
    NAMESPACE ${BINARY_NAME}::
)

target_include_directories(${BINARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/inc>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

addTestDir(test)
