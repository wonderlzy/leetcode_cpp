//
//  238_product_except_self.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _38_product_except_self_h
#define _38_product_except_self_h

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const size_t n = nums.size();
        vector<int> fwd(n, 1), bwd(n, 1), res(n);
        
        for(int i=0; i<n-1; ++i)
            fwd[i+1] = fwd[i] * nums[i];
        
        for(int j=n-1; j>0; --j)
            bwd[j-1] = bwd[j] * nums[j];
        
        for(int i=0; i<n; ++i)
            res[i] = fwd[i] * bwd[i];
        
        return res;
    }
};

#endif /* _38_product_except_self_h */
