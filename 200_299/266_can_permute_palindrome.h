//
//  266_can_permute_palindrome.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _66_can_permute_palindrome_h
#define _66_can_permute_palindrome_h

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int cnt = 0;
        for (auto a : s) ++m[a];
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second % 2) ++cnt;
        }
        return cnt == 0 || (s.size() % 2 == 1 && cnt == 1);
    }
};

#endif /* _66_can_permute_palindrome_h */
