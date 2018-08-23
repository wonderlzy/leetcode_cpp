//
//  754_reach_number.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _54_reach_number_h
#define _54_reach_number_h

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);
        long sum = n * (n + 1) / 2;
        if (sum == target) return n;
        long res = sum - target;
        if ((res & 1) == 0) return n;
        else return n + ((n & 1) ? 2 : 1);
    }
};

#endif /* _54_reach_number_h */
