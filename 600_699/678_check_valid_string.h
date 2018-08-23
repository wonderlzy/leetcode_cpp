//
//  678_check_valid_string.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _78_check_valid_string_h
#define _78_check_valid_string_h

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                ++low; ++high;
            } else if (c == ')') {
                if (low > 0) --low;
                --high;
            } else {
                if (low > 0) --low;
                ++high;
            }
            if (high < 0) return false;
        }
        return low == 0;
    }
};

#endif /* _78_check_valid_string_h */
