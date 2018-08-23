//
//  645_find_error_nums.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _45_find_error_nums_h
#define _45_find_error_nums_h

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, -1);
        for (int i : nums) {
            if (nums[abs(i) - 1] < 0) res[0] = abs(i);
            else nums[abs(i) - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) res[1] = i + 1;
        }
        return res;
    }
};

#endif /* _45_find_error_nums_h */
