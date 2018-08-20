//
//  461_hamming_distance.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _61_hamming_distance_h
#define _61_hamming_distance_h

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, exc = x ^ y;
        for (int i = 0; i < 32; ++i) {
            res += (exc >> i) & 1;
        }
        return res;
        /*
         int res = 0, exc = x ^ y;
         while (exc) {
         ++res;
         exc &= (exc - 1);
         }
         return res;
         */
    }
};

#endif /* _61_hamming_distance_h */
