add_library(
    libtradebot
    src/tradebot.cpp
)

target_include_directories(
    libtradebot 
    PRIVATE ${PROJECT_SOURCE_DIR}/common_include
    PUBLIC include
    PRIVATE ${CMAKE_SOURCE_DIR}/curlmanager/include
    PRIVATE ${CMAKE_SOURCE_DIR}/exchanges/include
)