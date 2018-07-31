//
//  174_caculate_minimum_hp.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _74_caculate_minimum_hp_h
#define _74_caculate_minimum_hp_h

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()) return 1;
        const size_t m = dungeon.size();
        const size_t n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m][n-1] = 1, dp[m-1][n] = 1;
        
        for(int i=m-1; i>=0; --i){
            for(int j=n-1; j>=0; --j){
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};

#endif /* _74_caculate_minimum_hp_h */
