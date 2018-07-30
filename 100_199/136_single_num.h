//
//  136_single_num.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _36_single_num_h
#define _36_single_num_h

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto num : nums)
            res ^= num;
        return res;
    }
};

#endif /* _36_single_num_h */
