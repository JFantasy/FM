/**
 * @file config.h
 * @author jishenghuai(jfantasy90@gmail.com)
 * @date 2013-07-04 10:07
 * @brief
 *
 **/

#ifndef __CONFIG_H_
#define __CONFIG_H_

#define ERROR_CODE 1

#define URL_LEN 500

enum Info_User {
    Id, Token, Expire, 
};

enum Info_Song {
    Title, Artist, Url,
};

#endif
