#pragma once

#include <curl/curl.h>
#include <iostream>

class CurlManager
{
public:
	CurlManager();
	~CurlManager();
	std::string getRequest(std::string url);
private:
	CURL *curl_;
	CURLcode res_;
};
