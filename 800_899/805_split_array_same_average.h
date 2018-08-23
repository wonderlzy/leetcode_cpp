//
//  805_average_array_same_average.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018年 zhongyingli. All rights reserved.
//

#ifndef _05_average_array_same_average_h
#define _05_average_array_same_average_h

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), m = n/2, totalSum = accumulate(A.begin(), A.end(), 0);
        sort(A.rbegin(), A.rend()); // Optimization
        for (int i = 1; i <= m; ++i)
            if (totalSum*i%n == 0 && combinationSum(A, 0, i, totalSum*i/n)) return true;
        return false;
    }
    bool combinationSum(vector<int>& nums, int idx, int k, int tar) {
        if (tar > k * nums[idx]) return false; // Optimization, A is sorted from large to small
        if (k == 0) return tar == 0;
        for (int i = idx; i <= nums.size()-k; ++i)
            if (nums[i] <= tar && combinationSum(nums, i+1, k-1, tar-nums[i])) return true;
        return false;
    }
};

#endif /* _05_average_array_same_average_h */
