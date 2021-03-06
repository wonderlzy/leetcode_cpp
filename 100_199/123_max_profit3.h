//
//  123_max_profit3.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _23_max_profit3_h
#define _23_max_profit3_h

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size(), global[n][3] = {0}, local[n][3] = {0};
        
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
                global[i][j] = max(local[i][j], global[i - 1][j]);
            }
        }
        return global[n - 1][2];
    }
};

#endif /* _23_max_profit3_h */
