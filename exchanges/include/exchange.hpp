#pragma once

#include "curlmanager.hpp"

enum class ExchangeType
{
    ERROR,
    BINANCE,
    KUCOIN
};

class Exchange 
{
public:
    virtual std::string getBalance() = 0;
protected:
    CurlManager curlManager_;
    std::string baseURL;
};