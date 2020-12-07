#include "exchange.hpp"
#include "common.h"
#include "arbitrage_pair.hpp"

class TradeBot
{
public:
    void addExchange(std::unique_ptr<Exchange> exchange);
    void printExchangeList();
    void updatePriceLists();

    void parseETHBTC();
    void compareETHBTC();

    void enableArbitrage();
    void disableArbitrage();

    void run();
private:
    float value;
    std::vector<std::unique_ptr<Exchange>> exchangeList_;

    ArbitragePair arbitragePair;

    //TRADING MODES
    bool arbitrageMode_ = false;
};