#include "binance.hpp"

std::string Binance::getBalance()
{
    curlManager_.getRequest(priceURL_);
}