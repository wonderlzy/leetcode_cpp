//
//  713_subarray_product_lessK.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _13_subarray_product_lessK_h
#define _13_subarray_product_lessK_h

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0, prod = 1, left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            while (prod >= k) prod /= nums[left++];
            res += i - left + 1;
        }
        return res;
    }
};

#endif /* _13_subarray_product_lessK_h */
