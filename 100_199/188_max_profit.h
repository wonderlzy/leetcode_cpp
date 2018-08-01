//
//  188_max_profit.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _88_max_profit_h
#define _88_max_profit_h

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        if(k >= prices.size()) return solveMaxProfit(prices);
        vector<int> l(k+1, 0);
        vector<int> g(k+1, 0);
        
        for(int i=0; i<prices.size()-1; ++i){
            int diff = prices[i+1] - prices[i];
            
            for(int j=k; j>=1; --j){
                l[j] = max(l[j] + diff, g[j-1] + max(0, diff));
                g[j] = max(g[j], l[j]);
            }
        }
        
        return g[k];
    }
private:
    int solveMaxProfit(vector<int>& prices){
        int res = 0;
        for(int i=1; i<prices.size(); ++i){
            if(prices[i] - prices[i-1] > 0)
                res += prices[i] - prices[i-1];
        }
        
        return res;
    }
};

#endif /* _88_max_profit_h */
