set(BINARY_NAME lib_target)

add_library(${BINARY_NAME}
    # Add sources for library here.
)

setupFlags(${BINARY_NAME})
target_include_directories(${BINARY_NAME} PUBLIC inc)

