#include "arbitrage_pair.hpp"

void ArbitragePair::setSmaller(Exchange* smaller)
{
    smaller_ = smaller;
}

void ArbitragePair::setLarger(Exchange* larger)
{
    larger_ = larger;
}

void ArbitragePair::executeTrade()
{
    if(smaller_ == nullptr || larger_ == nullptr)
    {
        std::cout << "ArbitragePair::executeTrade, nullptr";
        return;
    }

    std::cout << "Buying from " << smaller_->getExchangeName() << " and selling to " << larger_->getExchangeName() << std::endl;
}