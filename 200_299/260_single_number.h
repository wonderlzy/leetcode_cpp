//
//  260_single_number.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _60_single_number_h
#define _60_single_number_h

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        int num = 0, index = 0;
        for(auto n : nums)
            num ^= n;
        
        while( (num&1) == 0){
            num >>= 1;
            ++index;
        }
        
        for(auto n : nums){
            if(n>>index & 1)
                res[0] ^= n;
            else
                res[1] ^= n;
        }
        
        return res;
    }
};

#endif /* _60_single_number_h */
