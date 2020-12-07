cmake_minimum_required(VERSION 3.13.4)
project(tradebot)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/external)

add_subdirectory(curlmanager)
add_subdirectory(exchanges)
add_subdirectory(timer)
add_subdirectory(libtradebot)

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
    libtradebot
)