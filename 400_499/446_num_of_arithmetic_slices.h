//
//  446_num_of_arithmetic_slices.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _46_num_of_arithmetic_slices_h
#define _46_num_of_arithmetic_slices_h

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size();
        vector<unordered_map<int, int>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long delta = (long)A[i] - A[j];
                if (delta > INT_MAX || delta < INT_MIN) continue;
                int diff = (int)delta;
                ++dp[i][diff];
                if (dp[j].count(diff)) {
                    res += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        return res;
    }
};

#endif /* _46_num_of_arithmetic_slices_h */
