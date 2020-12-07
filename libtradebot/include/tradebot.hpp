#include "exchange.hpp"
#include "common.h"

class TradeBot
{
public:
    void addExchange(std::unique_ptr<Exchange> exchange);
    void printExchangeList();
    void updatePriceLists();

    void parseETHBTC();
    void compareETHBTC();

    void run();
private:
    float value;
    std::vector<std::unique_ptr<Exchange>> exchangeList_;
};