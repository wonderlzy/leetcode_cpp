//
//  152_max_product.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _52_max_product_h
#define _52_max_product_h

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = nums[0];
        const size_t n = nums.size();
        
        vector<int> big(n, 0);
        vector<int> small(n, 0);
        
        big[0] = nums[0];
        small[0] = nums[0];
        
        for(int i=1; i<nums.size(); ++i){
            big[i] = max(max(big[i-1]*nums[i], small[i-1]*nums[i]), nums[i]);
            small[i] = min(min(big[i-1]*nums[i], small[i-1]*nums[i]), nums[i]);
            res = max(big[i], res);
        }
        
        
        return res;
    }
};

#endif /* _52_max_product_h */
