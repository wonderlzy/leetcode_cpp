//
//  375_get_money_amount2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _75_get_money_amount2_h
#define _75_get_money_amount2_h

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 2; i <= n; ++i) {
            for (int j = i - 1; j > 0; --j) {
                int global_min = INT_MAX;
                for (int k = j + 1; k < i; ++k) {
                    int local_max = k + max(dp[j][k - 1], dp[k + 1][i]);
                    global_min = min(global_min, local_max);
                }
                dp[j][i] = j + 1 == i ? j : global_min;
            }
        }
        return dp[1][n];
    }
};

#endif /* _75_get_money_amount2_h */
