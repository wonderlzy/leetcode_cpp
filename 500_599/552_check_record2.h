//
//  552_check_record2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _52_check_record2_h
#define _52_check_record2_h

class Solution {
public:
    int checkRecord(int n) {
        int M = 1000000007;
        int dp[n + 1][2][3] = {0};
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[0][j][k] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int val = dp[i - 1][j][2];
                    if (j > 0) val = (val + dp[i - 1][j - 1][2]) % M;
                    if (k > 0) val = (val + dp[i - 1][j][k - 1]) % M;
                    dp[i][j][k] = val;
                }
            }
        }
        return dp[n][1][2];
    }
};

#endif /* _52_check_record2_h */
