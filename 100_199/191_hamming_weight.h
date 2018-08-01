//
//  191_hamming_weight.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _91_hamming_weight_h
#define _91_hamming_weight_h

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        
        for(int i=0; i<32; ++i){
            res += n & 1;
            n = n >> 1;
        }
        
        return res;
    }
};

#endif /* _91_hamming_weight_h */
