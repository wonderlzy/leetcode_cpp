//
//  53_max_subarray.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/28.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _3_max_subarray_h
#define _3_max_subarray_h

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return INT_MIN;
        int result = INT_MIN;
        int sum = 0;
        for_each(nums.begin(), nums.end(), [&](int e){
            sum = sum>0 ? sum+e : e;
            result = sum>result ? sum : result;
        });
        
        return result;
    }
};

#endif /* _3_max_subarray_h */
