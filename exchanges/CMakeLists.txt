add_library(
    exchange
    src/binance.cpp
    src/bittrex.cpp
)

target_include_directories(
    exchange 
    PRIVATE ${PROJECT_SOURCE_DIR}/common_include
    PUBLIC include
    PRIVATE ${CMAKE_SOURCE_DIR}/curlmanager/include
)