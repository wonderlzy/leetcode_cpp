//
//  790_num_tilings.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _90_num_tilings_h
#define _90_num_tilings_h

class Solution {
public:
    int numTilings(int N) {
        int M = 1e9 + 7;
        vector<long> dp(N + 1);
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= N; ++i) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % M;
        }
        return dp[N];
    }
};

#endif /* _90_num_tilings_h */
