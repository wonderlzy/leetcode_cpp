//
//  423_original_digits.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/17.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _23_original_digits_h
#define _23_original_digits_h

class Solution {
public:
    string originalDigits(string s) {
        string res = "";
        vector<int> counts(128, 0), nums(10, 0);
        for (char c : s) ++counts[c];
        nums[0] = counts['z'];
        nums[2] = counts['w'];
        nums[4] = counts['u'];
        nums[6] = counts['x'];
        nums[8] = counts['g'];
        nums[1] = counts['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = counts['h'] - nums[8];
        nums[5] = counts['f'] - nums[4];
        nums[7] = counts['s'] - nums[6];
        nums[9] = counts['i'] - nums[6] - nums[8] - nums[5];
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i]; ++j) {
                res += (i + '0');
            }
        }
        return res;
    }
};

#endif /* _23_original_digits_h */
