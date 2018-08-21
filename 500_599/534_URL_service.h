//
//  534_URL_service.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _34_URL_service_h
#define _34_URL_service_h

class URLService {
public:
    URLService() {
        COUNTER = 1;
        elements = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    
    string longToShort(string url) {
        string short_url = base10ToBase62(COUNTER);
        long2short[url] = COUNTER;
        short2long[COUNTER] = url;
        ++COUNTER;
        return "http://tiny.url/" + short_url;
    }
    
    string shortToLong(string url) {
        string prefix = "http://tiny.url/";
        url = url.substr(prefix.size());
        int n = base62ToBase10(url);
        return short2long[n];
    }
    
    int base62ToBase10(string s) {
        int n = 0;
        for (int i = 0; i < s.size(); ++i) {
            n = n * 62 + convert(s[i]);
        }
        return n;
    }
    
    int convert(char c) {
        if (c >= '0' && c <= '9') {
            return c - '0';
        } else if (c >= 'a' && c <= 'z') {
            return c - 'a' + 10;
        } else if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 36;
        }
        return -1;
    }
    
    string base10ToBase62(int n) {
        string str = "";
        while (n != 0) {
            str.insert(str.begin(), elements[n % 62]);
            n /= 62;
        }
        while (str.size() != 6) {
            str.insert(str.begin(), '0');
        }
        return str;
    }
    
private:
    unordered_map<string, int> long2short;
    unordered_map<int, string> short2long;
    int COUNTER;
    string elements;
};

#endif /* _34_URL_service_h */
