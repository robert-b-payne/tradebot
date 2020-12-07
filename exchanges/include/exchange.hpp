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
    virtual void fetchPriceList() = 0;
    virtual float getPriceETHBTC() = 0;
    virtual std::string getExchangeName() = 0;
protected:
    CurlManager curlManager_;
    std::string baseURL_;
    std::string exchangeName_;
};