#pragma once

#include "exchange.hpp"
#include <iostream>
#include "common.h"

class Binance : Exchange 
{
public:
    Binance(){ std::cout << "this is binance!\n";}
    std::string getBalance() override;
private:
    // std::string baseURL_ = "https://api.binance.com";
    std::string baseURL_ = "https://www.binance.com/api";

    std::string priceURL_ = "https://www.binance.com/api/v3/ticker/price";




    // https://www.binance.com/api/v3/ticker/price
};