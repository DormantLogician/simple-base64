set(BINARY_NAME lib)

add_library(${BINARY_NAME}
    # Add sources for library here.
)

generate_export_header(${BINARY_NAME})

set_target_properties(${BINARY_NAME} PROPERTIES PUBLIC_HEADER
    "inc/${BINARY_NAME}/public/fn/fn.h; \
    inc/${BINARY_NAME}/public/cl/cl.h; \
    inc/${BINARY_NAME}/public/def/def.h"
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
    DESTINATION "${CMAKE_INSTALL_PREFIX}/pkg/cmake"
    NAMESPACE ${BINARY_NAME}::
)

target_include_directories(${BINARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/inc>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Please fill in (if applicable) test targets as described below.
# addTestDir(test)
