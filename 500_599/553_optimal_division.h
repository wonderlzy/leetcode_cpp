//
//  553_optimal_division.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _53_optimal_division_h
#define _53_optimal_division_h

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res = "";
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0) res += "/";
            if (i == 1 && n > 2) res += "(";
            res += to_string(nums[i]);
            if (i == n - 1 && n > 2) res += ")";
        }
        return res;
    }
};

#endif /* _53_optimal_division_h */
