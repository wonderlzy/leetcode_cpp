//
//  345_reverse_vowels.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _45_reverse_vowels_h
#define _45_reverse_vowels_h

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        string t = "aeiouAEIOU";
        while (left < right) {
            if (t.find(s[left]) == string::npos) ++left;
            else if (t.find(s[right]) == string::npos) --right;
            else swap(s[left++], s[right--]);
        }
        return s;
    }
};

#endif /* _45_reverse_vowels_h */
