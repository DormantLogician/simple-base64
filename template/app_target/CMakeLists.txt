set(BINARY_NAME app_target)

add_executable(${BINARY_NAME}
    main.cpp
)

setupFlags(${BINARY_NAME})
target_include_directories(${BINARY_NAME} PRIVATE inc)
