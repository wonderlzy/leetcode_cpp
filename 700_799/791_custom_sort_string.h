//
//  791_custom_sort_string.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _91_custom_sort_string_h
#define _91_custom_sort_string_h

class Solution {
public:
    string customSortString(string S, string T) {
        string res = "";
        unordered_map<char, int> m;
        for (char c : T) ++m[c];
        for (char c : S) {
            res += string(m[c], c);
            m[c] = 0;
        }
        for (auto a : m) {
            res += string(a.second, a.first);
        }
        return res;
    }
};

#endif /* _91_custom_sort_string_h */
