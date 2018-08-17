//
//  416_can_partition.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/15.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _16_can_partition_h
#define _16_can_partition_h


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum >> 1;
        if(sum & 1) return false;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        
        for(auto num : nums){
            for(int i=target; i>=num; --i){
                dp[i] = dp[i] || dp[i-num];
            }
        }
        
        return dp[target];
    }
};

#endif /* _16_can_partition_h */
