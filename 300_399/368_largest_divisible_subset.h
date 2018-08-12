//
//  368_largest_divisible_subset.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _68_largest_divisible_subset_h
#define _68_largest_divisible_subset_h

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0), parent(nums.size(), 0), res;
        int mx = 0, mx_idx = 0;
        
        for(int i=nums.size()-1; i>=0; --i){
            for(int j=i; j<nums.size(); ++j){
                if(nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if(mx < dp[i]){
                        mx = dp[i];
                        mx_idx = i;
                    }
                }
            }
        }
        
        for(int i=0; i<mx; ++i){
            res.push_back(nums[mx_idx]);
            mx_idx = parent[mx_idx];
        }
        
        return res;
    }
};

#endif /* _68_largest_divisible_subset_h */
