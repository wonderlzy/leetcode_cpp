//
//  377_combination_sum4.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _77_combination_sum4_h
#define _77_combination_sum4_h

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for(int i=1; i<=target; ++i){
            for(auto num : nums){
                if(i < num)
                    break;
                dp[i] += dp[i-num];
            }
        }
        
        return dp.back();
        /*
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(int i=1; i<=target; ++i){
            for(auto num : nums){
                if(i >= num)
                    dp[i] += dp[i-num];
            }
        }
        
        return dp.back();
        */
    }
};

#endif /* _77_combination_sum4_h */
