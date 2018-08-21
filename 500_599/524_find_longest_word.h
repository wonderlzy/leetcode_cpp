//
//  524_find_longest_word.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _24_find_longest_word_h
#define _24_find_longest_word_h

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (string str : d) {
            int i = 0;
            for (char c : s) {
                if (i < str.size() && c == str[i]) ++i;
            }
            if (i == str.size() && str.size() >= res.size()) {
                if (str.size() > res.size() || str < res) {
                    res = str;
                }
            }
        }
        return res;
    }
};

#endif /* _24_find_longest_word_h */
