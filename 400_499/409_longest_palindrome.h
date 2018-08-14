//
//  409_longest_palindrome.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/15.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _09_longest_palindrome_h
#define _09_longest_palindrome_h

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        bool mid = false;
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        for (auto it = m.begin(); it != m.end(); ++it) {
            res += it->second;
            if (it->second % 2 == 1) {
                res -= 1;
                mid = true;
            }
        }
        return mid ? res + 1 : res;
    }
};

#endif /* _09_longest_palindrome_h */
