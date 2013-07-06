/**
 * @file userinfo.cpp
 * @author jishenghuai(jfantasy90@gmail.com)
 * @date 2013-07-04 09:59
 * @brief
 *
 **/

#include "userinfo.h"

UserInfo::UserInfo() : id_(""), token_(""), expire_("") {
}

UserInfo::~UserInfo() {
}

int UserInfo::SetInfo(const string &val, const Info_User &flag) {
    if (flag == Id) id_ = val;
    else if (flag == Token) token_ = val;
    else expire_ = val;
    return 0;
}

int UserInfo::GetInfo(const Info_User &flag, string &response) const {
    if (flag == Id) response = id_;
    else if (flag == Token) response = token_;
    else response = expire_;
    return 0;
}
