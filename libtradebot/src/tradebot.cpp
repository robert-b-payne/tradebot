#include "tradebot.hpp"

void TradeBot::addExchange(std::unique_ptr<Exchange> exchange)
{
    std::cout << "TradeBot::addExchange" << std::endl;
    exchangeList_.emplace_back(std::move(exchange));
    std::cout << "added " << exchangeList_[exchangeList_.size()-1]->getExchangeName() << std::endl;
}

void TradeBot::printExchangeList()
{
    std::cout << "TradeBot::printExchangeList" << std::endl;
    for(auto& exchange : exchangeList_)
    {
        std::cout << exchange->getExchangeName() << std::endl;
    }
}

void TradeBot::updatePriceLists()
{
    for(auto& exchange : exchangeList_)
    {
        exchange->fetchPriceList();
    }
}

void TradeBot::parseETHBTC()
{
    for(auto& exchange : exchangeList_)
    {
        exchange->getPriceETHBTC();
    }
}

void TradeBot::compareETHBTC()
{
    if(exchangeList_.size() == 0)
    {
        std::cerr << "exchangeList_ is empty!" << std::endl;
        return;
    }

    Exchange* smallest = exchangeList_[0].get();
    Exchange* largest = exchangeList_[0].get();

    for(auto& exchange : exchangeList_)
    {
        double price = exchange->getPriceETHBTC();
        if(price > largest->getPriceETHBTC())
        {
            largest = exchange.get();
        }
        else if(price < smallest->getPriceETHBTC())
        {
            smallest = exchange.get();
        }
    }
    std::cout << "Smallest ETHBTC price:\t[" <<  smallest->getExchangeName() << ", " << smallest->getPriceETHBTC() << "]" << std::endl;
    std::cout << "Largest ETHBTC price:\t[" <<  largest->getExchangeName() << ", " << largest->getPriceETHBTC() << "]" << std::endl;
    std::cout << largest->getExchangeName() << " is " << largest->getPriceETHBTC() / smallest->getPriceETHBTC() - 1 << "% larger than " << smallest->getExchangeName() << std::endl;
}

void TradeBot::run()
{
    std::cout << "running tradebot . . . " << std::endl;
    const auto callback = [&](){
        std::cout << "entering callback!" << std::endl;
        while(1)
        {
            usleep(1000 * 1000);
            updatePriceLists();
            parseETHBTC();
            compareETHBTC();
            std::cout << std::endl;
        }
    };

	std::thread t(callback);
	t.join();
}