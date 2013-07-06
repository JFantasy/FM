/**
 * @file httpcurl.cpp
 * @author jishenghuai(jfantasy90@gmail.com)
 * @date 2013-07-04 09:18
 * @brief
 *
 **/

#include "httpcurl.h"

#include <curl/curl.h>

using std::string;

HttpCurl::HttpCurl() {
}

HttpCurl::~HttpCurl() {
}

int HttpCurl::Get(const string &url, string &response) {
    CURLcode res;
    CURL *curl = curl_easy_init();
    if (curl == NULL) return CURLE_FAILED_INIT;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return res;
}

size_t HttpCurl::WriteData(void* buffer, size_t size, size_t nmemb, void* lpVoid) {
    string* str = dynamic_cast<string*>((string *)lpVoid);
    if (str == NULL || buffer == NULL) return -1;
    char* pData = (char*)buffer;
    str->append(pData, size * nmemb);
    return nmemb;
}
