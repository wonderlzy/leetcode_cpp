//
//  122_max_profit2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _22_max_profit2_h
#define _22_max_profit2_h

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for(int i=1; i<prices.size(); ++i){
            int diff = prices[i] - prices[i-1];
            if(diff > 0)
                sum += diff;
        }
        
        return sum;
    }
};

#endif /* _22_max_profit2_h */
