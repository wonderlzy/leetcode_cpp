//
//  741_cherry_pickup.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _41_cherry_pickup_h
#define _41_cherry_pickup_h

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), mx = 2 * n - 1;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = grid[0][0];
        for (int k = 1; k < mx; ++k) {
            for (int i = n - 1; i >= 0; --i) {
                for (int p = n - 1; p >= 0; --p) {
                    int j = k - i, q = k - p;
                    if (j < 0 || j >= n || q < 0 || q >= n || grid[i][j] < 0 || grid[p][q] < 0) {
                        dp[i][p] = -1;
                        continue;
                    }
                    if (i > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p]);
                    if (p > 0) dp[i][p] = max(dp[i][p], dp[i][p - 1]);
                    if (i > 0 && p > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);
                    if (dp[i][p] >= 0) dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0);
                }
            }
        }
        return max(dp[n - 1][n - 1], 0);
    }
};

#endif /* _41_cherry_pickup_h */
