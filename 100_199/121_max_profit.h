//
//  121_max_profit.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/28.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _21_max_profit_h
#define _21_max_profit_h

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int buyPrice = INT_MAX;
        int profit = 0;
        
        for(auto price : prices){
            buyPrice = min(buyPrice, price);
            profit = max(profit, price-buyPrice);
        }
        
        return profit;
    }
};

#endif /* _21_max_profit_h */
