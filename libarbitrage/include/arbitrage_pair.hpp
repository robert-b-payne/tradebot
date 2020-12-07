#include "exchange.hpp"

class ArbitragePair
{
public:
    void setSmaller(Exchange* smaller);
    void setLarger(Exchange* larger);

    void executeTrade();
private:
    Exchange* smaller_ = nullptr;
    Exchange* larger_ = nullptr;
    bool MODE_ = false;
};