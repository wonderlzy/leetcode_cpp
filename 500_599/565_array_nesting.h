//
//  565_array_nesting.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _65_array_nesting_h
#define _65_array_nesting_h

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 1;
            while (nums[i] != i && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
                ++cnt;
            }
            res = max(res, cnt);
        }
        return res;
    }
};

#endif /* _65_array_nesting_h */
