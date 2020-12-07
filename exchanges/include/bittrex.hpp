#include "exchange.hpp"
#include "common.h"
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class Bittrex : public Exchange
{
public:
    void fetchPriceList();
    std::string getBalance() override;

    float getPriceETHBTC();

    std::string getExchangeName();
    
private:
    std::string priceURL_ = "https://api.bittrex.com/v3/markets/tickers";
    std::string priceList_;

    float parseETHBTC();
    float parseNANOBTC();

    float priceETHBTC_;

    std::string exchangeName_ = "Bittrex";
};