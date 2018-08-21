//
//  526_count_arrangement.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _26_count_arrangement_h
#define _26_count_arrangement_h

class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) nums[i] = i + 1;
        return helper(N, nums);
    }
    int helper(int n, vector<int>& nums) {
        if (n <= 0) return 1;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (n % nums[i] == 0 || nums[i] % n == 0) {
                swap(nums[i], nums[n - 1]);
                res += helper(n - 1, nums);
                swap(nums[i], nums[n - 1]);
            }
        }
        return res;
    }
};

#endif /* _26_count_arrangement_h */
