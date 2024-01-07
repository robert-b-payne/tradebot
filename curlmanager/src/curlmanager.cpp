#include "curlmanager.hpp"

namespace
{
size_t writefunc(void *ptr, size_t size, size_t nmemb, std::string *s) 
{
  s->append(static_cast<char *>(ptr), size*nmemb);
  return size*nmemb;
}
}	// namespace

CurlManager::CurlManager()
{
	curl_ = curl_easy_init();
}

CurlManager::~CurlManager()
{
	curl_easy_cleanup(curl_);;
}

std::string CurlManager::getRequest(std::string url)
{
	if(!curl_)
	{	
		std::cout << "CurlManager failed to initialize!";
		return "";
	}

	std::string output;
  curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl_, CURLOPT_CUSTOMREQUEST, "GET");
  curl_easy_setopt(curl_, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, writefunc);
	curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &output);

  /* Perform the request, res will get the return code */
  res_ = curl_easy_perform(curl_);
  /* Check for errors */
  if(res_ != CURLE_OK)
  fprintf(stderr, "curl_easy_perform() failed: %s\n",
          curl_easy_strerror(res_));

	return output;
}
