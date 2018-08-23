//
//  764_order_of_largest_plus_sign.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _64_order_of_largest_plus_sign_h
#define _64_order_of_largest_plus_sign_h

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int res = 0;
        vector<vector<int>> dp(N, vector<int>(N, N));
        for (auto mine : mines) dp[mine[0]][mine[1]] = 0;
        for (int i = 0; i < N; ++i) {
            int l = 0, r = 0, u = 0, d = 0;
            for (int j = 0, k = N - 1; j < N; ++j, --k) {
                dp[i][j] = min(dp[i][j], l = (dp[i][j] ? l + 1 : 0));
                dp[j][i] = min(dp[j][i], u = (dp[j][i] ? u + 1 : 0));
                dp[i][k] = min(dp[i][k], r = (dp[i][k] ? r + 1 : 0));
                dp[k][i] = min(dp[k][i], d = (dp[k][i] ? d + 1 : 0));
            }
        }
        for (int k = 0; k < N * N; ++k) res = max(res, dp[k / N][k % N]);
        return res;
    }
};

#endif /* _64_order_of_largest_plus_sign_h */
