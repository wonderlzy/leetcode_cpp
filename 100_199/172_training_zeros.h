//
//  172_training_zeros.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _72_training_zeros_h
#define _72_training_zeros_h

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n){
            res += n / 5;
            n /= 5;
        }
        
        return res;
    }
};

#endif /* _72_training_zeros_h */
