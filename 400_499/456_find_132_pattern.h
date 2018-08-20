//
//  456_find_132_pattern.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _56_find_132_pattern_h
#define _56_find_132_pattern_h

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < third) return true;
            else while (!s.empty() && nums[i] > s.top()) {
                third = s.top(); s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

#endif /* _56_find_132_pattern_h */
