//
//  714_max_profit.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _14_max_profit_h
#define _14_max_profit_h

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> sold(prices.size(), 0), hold = sold;
        hold[0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
        }
        return sold.back();
        
        /*
        int sold = 0, hold = -prices[0];
        for (int price : prices) {
            int t = sold;
            sold = max(sold, hold + price - fee);
            hold = max(hold, t - price);
        }
        return sold;
        */
    }
};

#endif /* _14_max_profit_h */
