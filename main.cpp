#include "common.h"
#include "tradebot.hpp"
#include "curlmanager.hpp"
#include "binance.hpp"
#include "bittrex.hpp"
#include "timer.hpp"
#include <vector>

int main()
{
	std::cout << "-===== tradebot build " << TRADEBOT_VERSION << " =====-" << std::endl;

	TradeBot tradebot;

	tradebot.addExchange(std::make_unique<Binance>());
	tradebot.addExchange(std::make_unique<Bittrex>());

	tradebot.run();
}