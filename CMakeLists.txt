cmake_minimum_required(VERSION 3.13.4)
project(tradebot)

add_subdirectory(CurlManager)

add_executable(tradebot
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(tradebot 
    curl
    curlmanager
)