//
//  120_minimum_total.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/28.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _20_minimum_total_h
#define _20_minimum_total_h

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return INT_MAX;
        size_t n = triangle.size();
        vector<int> dp(triangle.back());
        
        for(int i=triangle.size()-2; i>=0; --i){
            for(int j=0; j<=i; ++j){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        
        return dp[0];
    }
};

#endif /* _20_minimum_total_h */
