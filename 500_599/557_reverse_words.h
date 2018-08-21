//
//  557_reverse_words.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _57_reverse_words_h
#define _57_reverse_words_h

class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0, n = s.size();
        while (start < n && end < n) {
            while (end < n && s[end] != ' ') ++end;
            for (int i = start, j = end - 1; i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
            start = ++end;
        }
        return s;
    }
};

#endif /* _57_reverse_words_h */
