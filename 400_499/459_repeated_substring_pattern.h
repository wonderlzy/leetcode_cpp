//
//  459_repeated_substring_pattern.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _59_repeated_substring_pattern_h
#define _59_repeated_substring_pattern_h

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /*
         int i = 1, j = 0, n = s.size();
         vector<int> dp(n + 1, 0);
         while (i < n) {
         if (s[i] == s[j]) dp[++i] = ++j;
         else if (j == 0) ++i;
         else j = dp[j];
         }
         return dp[n] && (dp[n] % (n - dp[n]) == 0);
        */
        int n = s.size();
        for (int i = n / 2; i >= 1; --i) {
            if (n % i == 0) {
                int c = n / i;
                string t = "";
                for (int j = 0; j < c; ++j) {
                    t += s.substr(0, i);
                }
                if (t == s) return true;
            }
        }
        return false;
    }
};

#endif /* _59_repeated_substring_pattern_h */
