cmake_minimum_required(VERSION 3.15)

set(SOURCES
    main.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wconversion)
target_include_directories(${PROJECT_NAME} PRIVATE inc)
