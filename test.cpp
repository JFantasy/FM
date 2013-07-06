/**
 * @file test.cpp
 * @author jishenghuai(jfantasy90@gmail.com)
 * @date 2013-07-05 06:55
 * @brief
 *
 **/

#include "action.h"

#include <cstdio>

#include <string>
#include <vector>

using std::string;
using std::vector;

int main(int argv, char *argc[]) {
    Action *client = new Action();
    UserInfo *user = new UserInfo();
    if (argv == 3) {
        string email(argc[1]), pass(argc[2]);
        client->Login(email, pass, *user);
        string uid, expire, token;
        user->GetInfo(Id, uid);
        user->GetInfo(Expire, expire);
        user->GetInfo(Token, token);
        printf("%s||%s||%s\n", uid.c_str(), expire.c_str(), token.c_str());
    } else {
        vector<SongInfo> *vec = new vector<SongInfo>();
        user->SetInfo(string(argc[1]), Id);
        user->SetInfo(string(argc[2]), Expire);
        user->SetInfo(string(argc[3]), Token);
        client->GetSongList(*user, *vec);
        for (int i = 0; i < vec->size(); ++ i) {
            string title, artist, url;
            vec->at(i).GetInfo(Title, title);
            vec->at(i).GetInfo(Artist, artist);
            vec->at(i).GetInfo(Url, url);
            printf("%s||%s||%s\n", title.c_str(), artist.c_str(), url.c_str());
        }
        delete vec;
    }
    delete client;
    delete user;
    return 0;
}
