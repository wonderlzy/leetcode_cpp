//
//  656_cheapest_jump.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _56_cheapest_jump_h
#define _56_cheapest_jump_h

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        if (A.back() == -1) return {};
        int n = A.size();
        vector<int> res, dp(n, INT_MAX), pos(n, -1);
        dp[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] == -1) continue;
            for (int j = i + 1; j <= min(i + B, n - 1); ++j) {
                if (dp[j] == INT_MAX) continue;
                if (A[i] + dp[j] < dp[i]) {
                    dp[i] = A[i] + dp[j];
                    pos[i] = j;
                }
            }
        }
        if (dp[0] == INT_MAX) return res;
        for (int cur = 0; cur != -1; cur = pos[cur]) {
            res.push_back(cur + 1);
        }
        return res;
    }
};

#endif /* _56_cheapest_jump_h */
