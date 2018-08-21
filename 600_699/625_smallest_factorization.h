//
//  625_smallest_factorization.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _25_smallest_factorization_h
#define _25_smallest_factorization_h

class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) return 1;
        string res = "";
        for (int k = 9; k >= 2; --k) {
            while (a % k == 0) {
                res = to_string(k) + res;
                a /= k;
            }
        }
        if (a > 1) return 0;
        long long num = stoll(res);
        return num > INT_MAX ? 0 : num;
    }
};

#endif /* _25_smallest_factorization_h */
