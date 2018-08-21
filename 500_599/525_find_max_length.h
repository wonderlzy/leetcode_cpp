//
//  525_find_max_length.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _25_find_max_length_h
#define _25_find_max_length_h

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < n; ++i) {
            sum += (nums[i] == 1) ? 1 : -1;
            if (m.count(sum)) {
                res = max(res, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return res;
    }
};

#endif /* _25_find_max_length_h */
