//
//  628_maximum_product.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _28_maximum_product_h
#define _28_maximum_product_h

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int p = nums[0] * nums[1] * nums[n - 1];
        return max(p, nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};

#endif /* _28_maximum_product_h */
