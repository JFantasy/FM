/**
 * @file songinfo.cpp
 * @author jishenghuai(jfantasy90@gmail.com)
 * @date 2013-07-04 10:15
 * @brief
 *
 **/

#include "songinfo.h"

SongInfo::SongInfo() : title_(""), artist_(""), url_("") {
}

SongInfo::~SongInfo() {
}

int SongInfo::SetInfo(const string &val, const Info_Song &flag) {
    if (flag == Title) title_ = val;
    else if (flag == Artist) artist_ = val;
    else url_ = val;
    return 0;
}

int SongInfo::GetInfo(const Info_Song &flag, string &response) {
    if (flag == Title) response = title_;
    else if (flag == Artist) response = artist_;
    else response = url_;
    return 0;
}
