//
//  485_find_max_consecutive_ones.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _85_find_max_consecutive_ones_h
#define _85_find_max_consecutive_ones_h

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            cnt = (num == 0) ? 0 : cnt + 1;
            res = max(res, cnt);
        }
        return res;
    }
};

#endif /* _85_find_max_consecutive_ones_h */
