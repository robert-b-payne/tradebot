#pragma once

#include "exchange.hpp"
#include <iostream>
#include "common.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class Binance : public Exchange 
{
public:
    std::string getBalance() override;
    void fetchPriceList();

    float getPriceETHBTC();
    std::string getExchangeName();
private:
    // std::string baseURL_ = "https://api.binance.com";
    std::string baseURL_ = "https://www.binance.com/api";
    std::string priceURL_ = "https://www.binance.com/api/v3/ticker/price";
    std::string priceList_;

    float parseETHBTC();

    float priceETHBTC_;

    std::string exchangeName_ = "Binance";


    // https://www.binance.com/api/v3/ticker/price
};