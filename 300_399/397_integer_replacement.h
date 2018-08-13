//
//  397_integer_replacement.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _97_integer_replacement_h
#define _97_integer_replacement_h

class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n % 2 == 0) return 1 + integerReplacement(n / 2);
        else {
            long long t = n;
            return 2 + min(integerReplacement((t + 1) / 2), integerReplacement((t - 1) / 2));
        }
    }
};

#endif /* _97_integer_replacement_h */
