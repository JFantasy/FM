/**
 * @file httpcurl.h
 * @author jishenghuai(jfantasy90@gmail.com)
 * @date 2013-07-04 09:10
 * @brief
 *
 **/

#ifndef __HTTPCURL_H_
#define __HTTPCURL_H_

#include <string>

using std::string;

class HttpCurl {
    public:
        HttpCurl();
        ~HttpCurl();

        int Get(const string &url, string &response);

    private:
        static size_t WriteData(void* buffer, size_t size, size_t nmemb, void* lpVoid);
};

#endif
