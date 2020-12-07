add_library(
    libarbitrage
    src/arbitrage_pair.cpp
)

target_include_directories(
    libarbitrage 
    PRIVATE ${PROJECT_SOURCE_DIR}/common_include
    PUBLIC include
    PRIVATE ${CMAKE_SOURCE_DIR}/exchanges/include
    PRIVATE ${CMAKE_SOURCE_DIR}/curlmanager/include
)