//
//  198_rob.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _98_rob_h
#define _98_rob_h

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        const size_t n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; ++i){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

#endif /* _98_rob_h */
