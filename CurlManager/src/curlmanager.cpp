#include "curlmanager.hpp"

CurlManager::CurlManager()
{
	std::cout << "CurlManager::CurlManager" << std::endl;
	curl_ = curl_easy_init();
}

bool CurlManager::getRequest(std::string url)
{
	if(!curl_)
	{	
		std::cout << "CurlManager failed to initialize!";
		return false;
	}	
	

   	//curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
   	curl_easy_setopt(curl_, CURLOPT_URL, "http://api.open-notify.org/astros.json");
   	curl_easy_setopt(curl_, CURLOPT_CUSTOMREQUEST, "GET");
   	/* example.com is redirected, so we tell libcurl to follow redirection */
   	curl_easy_setopt(curl_, CURLOPT_FOLLOWLOCATION, 1L);

   	/* Perform the request, res will get the return code */
   	res_ = curl_easy_perform(curl_);
   	/* Check for errors */
   	if(res_ != CURLE_OK)
    fprintf(stderr, "curl_easy_perform() failed: %s\n",
           curl_easy_strerror(res_));

   	/* always cleanup */
   	curl_easy_cleanup(curl_);
    printf("\n");


	return true;
}
