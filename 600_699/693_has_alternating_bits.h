//
//  693_has_alternating_bits.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _93_has_alternating_bits_h
#define _93_has_alternating_bits_h

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = -1;
        while (n > 0) {
            if (n & 1 == 1) {
                if (bit == 1) return false;
                bit = 1;
            } else {
                if (bit == 0) return false;
                bit = 0;
            }
            n >>= 1;
        }
        return true;
        
        /*
        int d = n & 1;
        while ((n & 1) == d) {
            d ^= 1;
            n >>= 1;
        }
        return n == 0;
         */
    }
};

#endif /* _93_has_alternating_bits_h */
