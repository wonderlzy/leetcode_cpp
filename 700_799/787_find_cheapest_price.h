//
//  787_find_cheapest_price.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _87_find_cheapest_price_h
#define _87_find_cheapest_price_h

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(K + 2, vector<int>(n, 1e9));
        dp[0][src] = 0;
        for (int i = 1; i <= K + 1; ++i) {
            dp[i][src] = 0;
            for (auto x : flights) {
                dp[i][x[1]] = min(dp[i][x[1]], dp[i - 1][x[0]] + x[2]);
            }
        }
        return (dp[K + 1][dst] >= 1e9) ? -1 : dp[K + 1][dst];
    }
};

#endif /* _87_find_cheapest_price_h */
