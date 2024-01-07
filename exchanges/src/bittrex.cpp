#include "bittrex.hpp"

std::string Bittrex::getBalance()
{
    std::cout << "Bittrex::getBalance" << std::endl;
    return "";
}

void Bittrex::fetchPriceList()
{
    priceList_ = curlManager_.getRequest(priceURL_);   
    priceList_.insert(0, "{\"data\":");
    priceList_ += "}";
    parseETHBTC();
}

float Bittrex::parseETHBTC()
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

        if( !strcmp(symbol->value.GetString(), "ETH-BTC") )
        {
            auto priceVal = element.FindMember("lastTradeRate");
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

float Bittrex::getPriceETHBTC()
{
    return priceETHBTC_;
}

std::string Bittrex::getExchangeName()
{
    return exchangeName_;
}