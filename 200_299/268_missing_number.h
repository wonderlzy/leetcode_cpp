//
//  268_missing_number.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _68_missing_number_h
#define _68_missing_number_h

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<nums.size(); ++i)
            res ^= (i+1) ^ nums[i];
        
        return res;
        
        /*
        int sum = 0;
        const size_t n = nums.size();
        for(auto num : nums)
            sum += num;
        
        return 0.5 * n * (n+1) - sum;
        */
    }
};

#endif /* _68_missing_number_h */
