//
//  762_count_prime_set_bits.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _62_count_prime_set_bits_h
#define _62_count_prime_set_bits_h

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; ++i) {
            int t = i, cnt = 0;
            while (t > 0) {
                if (t & 1 == 1) ++cnt;
                t >>= 1;
            }
            bool succ = true;
            for (int j = sqrt(cnt); j > 1; --j) {
                if (cnt % j == 0) {
                    succ = false; break;
                }
            }
            if (succ && cnt != 1) ++res;
        }
        return res;
    }
};

#endif /* _62_count_prime_set_bits_h */
