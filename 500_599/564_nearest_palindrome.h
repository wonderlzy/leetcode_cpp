//
//  564_nearest_palindrome.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _64_nearest_palindrome_h
#define _64_nearest_palindrome_h

class Solution {
public:
    string nearestPalindromic(string n) {
        long len = n.size(), num = stol(n), res, minDiff = LONG_MAX;
        unordered_set<long> s;
        s.insert(pow(10, len) + 1);
        s.insert(pow(10, len - 1) - 1);
        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (long i = -1; i <= 1; ++i) {
            string pre = to_string(prefix + i);
            string str = pre + string(pre.rbegin() + (len & 1), pre.rend());
            s.insert(stol(str));
        }
        s.erase(num);
        for (auto a : s) {
            long diff = abs(a - num);
            if (diff < minDiff) {
                minDiff = diff;
                res = a;
            } else if (diff == minDiff) {
                res = min(res, a);
            }
        }
        return to_string(res);
    }
};

#endif /* _64_nearest_palindrome_h */
