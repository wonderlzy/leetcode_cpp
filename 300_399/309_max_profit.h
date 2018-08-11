//
//  309_max_profit.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _09_max_profit_h
#define _09_max_profit_h

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        for(auto price : prices){
            pre_buy = buy;
            buy = max(pre_sell-price, pre_buy);
            pre_sell = sell;
            sell = max(pre_buy+price, pre_sell);
        }
        return sell;
    }
};

#endif /* _09_max_profit_h */
