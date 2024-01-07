#include "binance.hpp"

std::string Binance::getBalance()
{
    curlManager_.getRequest(priceURL_);
    return "";
}

void Binance::fetchPriceList()
{
    priceList_ = curlManager_.getRequest(priceURL_);
    priceList_.insert(0, "{\"data\":");
    priceList_ += "}";
    parseETHBTC();
}

float Binance::parseETHBTC()
{
    float price;
    rapidjson::Document d;
    d.Parse(priceList_.c_str());
    if(!d.IsObject())
    {
        std::cout << "it's not an object" << std::endl;
        return -100;
    }
    auto x = d.FindMember("data");
    if(x == d.MemberEnd() || !x->value.IsArray())
    {
        std::cout << "ccouldn't find data" << std::endl;
        return -100;
    }

    for(auto& element : x->value.GetArray())
    {
        if(!element.IsObject())
        {
            std::cout << "is not an object!" << std::endl;
            continue;
        }
        auto symbol = element.FindMember("symbol");
        if(symbol == element.MemberEnd())
        {
            std::cout << "couldn't find member called symbol" << std::endl;
            continue;
        }

        if( !strcmp(symbol->value.GetString(), "ETHBTC") )
        {
            auto priceVal = element.FindMember("price");
            if(priceVal != element.MemberEnd() && priceVal->value.IsString())
            {
                
                price = std::atof(priceVal->value.GetString());
            }
            break;
        }
    }

    priceETHBTC_ = price;

    return price;
}

float Binance::getPriceETHBTC()
{
    return priceETHBTC_;
}

std::string Binance::getExchangeName()
{
    return exchangeName_;
}