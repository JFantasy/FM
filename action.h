/**
 * @file 
 * @author jishenghuai(jfantasy90@gmail.com)
 * @date 2013-07-04 14:50
 * @brief
 *
 **/

#ifndef __ACTION_H_
#define __ACTION_H_

#include "songinfo.h"
#include "userinfo.h"
#include "httpcurl.h"
#include "config.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Action {
    public:
        Action();
        ~Action();

        int Login(const string &email, const string &pass, UserInfo &user);
        int GetSongList(const UserInfo &user, vector<SongInfo> &list);

    private:
        HttpCurl* client_;

        int UserFromJson(const string &info, UserInfo &user);
        int SongListFromJson(const string &info, vector<SongInfo> &list);
};

#endif
