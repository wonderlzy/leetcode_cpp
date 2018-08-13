//
//  387_find_unique_char.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _87_find_unique_char_h
#define _87_find_unique_char_h

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};

#endif /* _87_find_unique_char_h */
