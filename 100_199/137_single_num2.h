//
//  137_single_num2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _37_single_num2_h
#define _37_single_num2_h

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<32; ++i){
            int sum = 0;
            for(int j=0; j<nums.size(); ++j){
                sum += (nums[j] >> i) & 1;
            }
            
            res |= (sum % 3) << i;
        }
        
        return res;
    }
};

#endif /* _37_single_num2_h */
