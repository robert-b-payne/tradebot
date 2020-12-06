cmake_minimum_required(VERSION 3.13.4)
project(tradebot)

add_subdirectory(curlmanager)
add_subdirectory(exchanges)
add_subdirectory(timer)

add_executable(tradebot
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_include_directories(
    tradebot
    PRIVATE ${PROJECT_SOURCE_DIR}/common_include
)

target_link_libraries(tradebot 
    curl
    curlmanager
    exchange
    timer
    pthread
)