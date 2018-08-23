//
//  634_find_derangement.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _34_find_derangement_h
#define _34_find_derangement_h

class Solution {
public:
    int findDerangement(int n) {
        if (n < 2) return 0;
        vector<long long> dp(n + 1, 0);
        dp[1] = 0; dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1) % 1000000007;
        }
        return dp[n];
    }
};

#endif /* _34_find_derangement_h */
