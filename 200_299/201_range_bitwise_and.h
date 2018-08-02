//
//  201_range_bitwise_and.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _01_range_bitwise_and_h
#define _01_range_bitwise_and_h

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d = INT_MAX;
        while( (m&d) != (n&d)){
            d <<= 1;
        }
        
        return m&d;
    }
};

#endif /* _01_range_bitwise_and_h */
