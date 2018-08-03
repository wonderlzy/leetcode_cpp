//
//  213_rob2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _13_rob2_h
#define _13_rob2_h

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
    }
    
    int rob(vector<int>& nums, int left, int right){
        if(right - left <= 1)
            return nums[left];
        vector<int> dp(right, 0);
        dp[left] = nums[left];
        dp[left+1] = max(nums[left], nums[left+1]);
        
        for(int i=left+2; i<right; ++i){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        
        return dp.back();
    }
};

#endif /* _13_rob2_h */
