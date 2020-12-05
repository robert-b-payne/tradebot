#include <curl/curl.h>
#include <iostream>

class CurlManager
{
public:
	CurlManager();
	bool getRequest(std::string url);
private:
	CURL *curl_;
	CURLcode res_;
};
