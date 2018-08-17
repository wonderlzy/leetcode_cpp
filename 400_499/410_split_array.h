//
//  410_split_array.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/15.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _10_split_array_h
#define _10_split_array_h

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        //dp
        if(nums.empty() || nums.size() < m)
            return -1;
        int n = nums.size();
        vector<int> sums(n+1, 0);
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[0][0] = 0;
        for(int i=1; i<=n; ++i)
            sums[i] = sums[i-1] + nums[i-1];
        
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                for(int k=i-1; k<j; ++k){
                    int val = max(dp[i-1][k],sums[j]-sums[k]);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        
        return dp[m][n];
        
        /*
         if(nums.empty() || nums.size() < m) return -1;
        int left = 0, right = 0;
        for(auto num : nums){
            left = max(left, num);
            right += num;
        }
        
        while(left < right){
            int mid = left + (right-left) / 2;
            if(canSplit(nums, m, mid)) right = mid;
            else left = mid + 1;
        }
        
        return left;
        */
    }
    
    bool canSplit(vector<int>& nums, int m, int sum){
        int cnt = 1, curSum = 0;
        for(auto num : nums){
            curSum += num;
            if(curSum > sum){
                curSum = num;
                ++cnt;
                
                if(cnt > m) return false;
            }
        }
        
        return true;
    }
};

#endif /* _10_split_array_h */
