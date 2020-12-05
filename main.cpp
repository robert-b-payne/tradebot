#include <iostream>
#include "curlmanager.hpp"

int main()
{
	std::cout << "yo" << std::endl;
	CurlManager c;
	c.getRequest("hello");
}
