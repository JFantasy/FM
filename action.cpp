/**
 * @file action.cpp
 * @author jishenghuai(jfantasy90@gmail.com)
 * @date 2013-07-04 14:57
 * @brief
 *
 **/

#include "action.h"
#include "httpcurl.h"

#include <cstdio>

#include <algorithm>

#include "cJSON.h"

Action::Action() {
    client_ = new HttpCurl();
}

Action::~Action() {
    delete client_;
}

int Action::Login(const string &email, const string &pass, UserInfo &user) {
    const string user_url = "http://www.douban.com/j/app/login?app_name=radio_desktop_win&version=100&email=%s&password=%s";
    char url[URL_LEN];
    sprintf(url, user_url.c_str(), email.c_str(), pass.c_str());
    string res;
    client_->Get(string(url), res);
    return UserFromJson(res, user);
}

int Action::GetSongList(const UserInfo &user, vector<SongInfo> &list) {
    const string song_url = "http://www.douban.com/j/app/radio/people?app_name=radio_desktop_win&version=100&user_id=%s&expire=%s&token=%s&type=n&channel=0";
    char url[URL_LEN];
    string id, token, expire;
    if (user.GetInfo(Id, id) || user.GetInfo(Token, token) || user.GetInfo(Expire, expire)) return ERROR_CODE;
    sprintf(url, song_url.c_str(), id.c_str(), expire.c_str(), token.c_str());
    string res;
    client_->Get(string(url), res);
    return SongListFromJson(res, list);
}

int Action::UserFromJson(const string &info, UserInfo &user) {
    cJSON *json = cJSON_Parse(info.c_str());
    user.SetInfo(string(cJSON_GetObjectItem(json, "user_id")->valuestring), Id);
    user.SetInfo(string(cJSON_GetObjectItem(json, "token")->valuestring), Token);
    user.SetInfo(string(cJSON_GetObjectItem(json, "expire")->valuestring), Expire);
    return 0;
}

int Action::SongListFromJson(const string &info, vector<SongInfo> &list) {
    cJSON *arr, *json;
    json = cJSON_Parse(info.c_str());
    arr = cJSON_GetObjectItem(json, "song");
    int size = cJSON_GetArraySize(arr);
    for (int i = 0; i < size; ++ i) {
        SongInfo song;
        json = cJSON_GetArrayItem(arr, i);
        song.SetInfo(string(cJSON_GetObjectItem(json, "title")->valuestring), Title);
        song.SetInfo(string(cJSON_GetObjectItem(json, "artist")->valuestring), Artist);
        song.SetInfo(string(cJSON_GetObjectItem(json, "url")->valuestring), Url);
        list.push_back(song);
    }
    return 0;
}

