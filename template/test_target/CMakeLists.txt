set(BINARY_NAME targetname)
set(MODULE_NAME all_${BINARY_NAME}_specs)

makeTest(${MODULE_NAME} ${MODULE_NAME}.cpp)

add_subdirectory(specs_unitname)

target_link_libraries(${MODULE_NAME} PRIVATE ${BINARY_NAME}
    ${BINARY_NAME}_specs_unitname
)
