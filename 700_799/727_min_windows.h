//
//  727_min_windows.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _27_min_windows_h
#define _27_min_windows_h

class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size(), start = -1, minLen = INT_MAX, i = 0, j = 0;
        while (i < m) {
            if (S[i] == T[j]) {
                if (++j == n) {
                    int end = i + 1;
                    while (--j >= 0) {
                        while (S[i--] != T[j]);
                    }
                    ++i; ++j;
                    if (end - i < minLen) {
                        minLen = end - i;
                        start = i;
                    }
                }
            }
            ++i;
        }
        return (start != -1) ? S.substr(start, minLen) : "";
    }
};

#endif /* _27_min_windows_h */
