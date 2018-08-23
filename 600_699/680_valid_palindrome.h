//
//  680_valid_palindrome.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _80_valid_palindrome_h
#define _80_valid_palindrome_h

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return isValid(s, left, right - 1) || isValid(s, left + 1, right);
            ++left; --right;
        }
        return true;
    }
    bool isValid(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left; --right;
        }
        return true;
    }
};

#endif /* _80_valid_palindrome_h */
