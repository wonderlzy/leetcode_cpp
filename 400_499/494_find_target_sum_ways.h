//
//  494_find_target_sum_ways.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _94_find_target_sum_ways_h
#define _94_find_target_sum_ways_h

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        helper(nums, S, 0, res);
        return res;
    }
    void helper(vector<int>& nums, int S, int start, int& res) {
        if (start >= nums.size()) {
            if (S == 0) ++res;
            return;
        }
        helper(nums, S - nums[start], start + 1, res);
        helper(nums, S + nums[start], start + 1, res);
    }
    
    /*
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> dp(nums.size());
        return helper(nums, S, 0, dp);
    }
    int helper(vector<int>& nums, int sum, int start, vector<unordered_map<int, int>>& dp) {
        if (start == nums.size()) return sum == 0;
        if (dp[start].count(sum)) return dp[start][sum];
        int cnt1 = helper(nums, sum - nums[start], start + 1, dp);
        int cnt2 = helper(nums, sum + nums[start], start + 1, dp);
        return dp[start][sum] = cnt1 + cnt2;
    }
     */
    
    /*
    class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int S) {
            int total = 0;
            for (auto x : nums) total += x;
            if (total < S || (total - S) % 2 || (total - S)/2 > 1000) return 0;
            return subsetSum(nums, (total - S) / 2);
        }
    private:
        int subsetSum(vector<int> &nums, int target) {
            vector<int> f(target + 1, 0);
            sort(nums.begin(), nums.end());
            f[0] = 1;
            for (int j = 0; j < nums.size(); j++) {
                for (int i = target; i >= 0; i--) {
                    if (i - nums[j] >= 0) f[i] += f[i - nums[j]];
                    else break;
                }
            }
            return f[target];
        }
    };
    */
};

#endif /* _94_find_target_sum_ways_h */
