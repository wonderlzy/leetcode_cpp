//
//  818_racecar.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _18_racecar_h
#define _18_racecar_h

class Solution {
public:
    int dp[10001];
    int racecar(int t) {
        if (dp[t] > 0) return dp[t];
        int n = floor(log2(t)) + 1, res;
        if (1 << n == t + 1) dp[t] = n;
        else {
            dp[t] = racecar((1 << n) - 1 - t) + n + 1;
            for (int m = 0; m < n - 1; ++m)
                dp[t] = min(dp[t], racecar(t - (1 << (n - 1)) + (1 << m)) + n + m + 1);
        }
        return dp[t];
    }
};

#endif /* _18_racecar_h */
