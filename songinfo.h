/**
 * @file songinfo.h
 * @author jishenghuai(jfantasy90@gmail.com)
 * @date 2013-07-04 10:03
 * @brief
 *
 **/

#ifndef __SONGINFO_H_
#define __SONGINFO_H_

#include "config.h"

#include <string>

using std::string;

class SongInfo {
    public:
        SongInfo();
        ~SongInfo();

        int SetInfo(const string &val, const Info_Song &flag);
        int GetInfo(const Info_Song &flag, string &response);

    private:
        string title_, artist_, url_;
};

#endif
