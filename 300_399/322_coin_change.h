//
//  322_coin_change.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _22_coin_change_h
#define _22_coin_change_h

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=1; i<=amount; ++i){
            for(int j=0; j<coins.size(); ++j){
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
        /*
         sort(coins.begin(), coins.end());
         int res = INT_MAX;
         
         helper(res, coins, amount, coins.size() - 1, 0);
         
         return res == INT_MAX ? -1 : res;
        */
    }
    
    void helper(int& res, vector<int>& coins, int target, int idx, int count){
        if (idx < 0) return;
        if (target % coins[idx] == 0){
            res = min( res, count + target/coins[idx] );
            return;
        }
        
        for (int i=target/coins[idx]; i>=0; --i){
            if (count + i >= res - 1) break;    // pruing
            helper(res, coins, target - i * coins[idx], idx - 1, count + i);
        }
    }

};

#endif /* _22_coin_change_h */
