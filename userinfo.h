/**
 * @file userinfo.h
 * @author jishenghuai(jfantasy90@gmail.com)
 * @date 2013-07-04 09:50
 * @brief
 *
 **/

#ifndef __USERINFO_H_
#define __USERINFO_H_

#include "config.h"

#include <string>

using std::string;

class UserInfo {
    public:
        UserInfo();
        ~UserInfo();

        int SetInfo(const string &val, const Info_User &flag);
        int GetInfo(const Info_User &flag, string &response) const;

    private:
        string id_, token_, expire_;
};

#endif
