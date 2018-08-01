//
//  190_reverse_bits.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _90_reverse_bits_h
#define _90_reverse_bits_h

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0; i<32; ++i){
            if(n & 1 == 1){
                res = (res << 1) + 1;
            } else {
                res = res << 1;
            }
            
            n = n >> 1;
        }
        
        return res;
    }
};

#endif /* _90_reverse_bits_h */
