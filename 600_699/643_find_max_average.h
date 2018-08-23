//
//  643_find_max_average.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _43_find_max_average_h
#define _43_find_max_average_h

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0), res = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res / k;
    }
};

#endif /* _43_find_max_average_h */
