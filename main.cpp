#include "common.h"
#include <iostream>
#include "curlmanager.hpp"
#include "binance.hpp"
#include "timer.hpp"

int main()
{
	std::cout << "-===== tradebot build " << TRADEBOT_VERSION << " =====-" << std::endl;
	// std::cout << "yo" << std::endl;
	// CurlManager c;
	// c.getRequest("https://example.com");
	// c.getRequest("http://api.open-notify.org/astros.json");
	Binance b;
	Timer t;
	int counter = 0;
	auto callback = [&counter](){
		if(counter++ >= 5)
		{
			pthread_exit(NULL);
		}
		std::cout << "Hello!" << std::endl;
	};
	t.setInterval(callback, 700);
	// b.getBalance();
	while(1){}
}