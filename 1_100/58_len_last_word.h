//
//  58_len_last_word.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _8_len_last_word_h
#define _8_len_last_word_h

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        while(!s.empty() && s.back()==' ') s.pop_back();
        while (!s.empty() && s.back() != ' ') {
            s.pop_back();
            ++len;
        }
        return len;
    }
};

#endif /* _8_len_last_word_h */
