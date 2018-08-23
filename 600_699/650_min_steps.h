//
//  650_min_steps.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _50_min_steps_h
#define _50_min_steps_h

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        int res = n;
        for (int i = n - 1; i > 1; --i) {
            if (n % i == 0) {
                res = min(res, minSteps(n / i) + i);
            }
        }
        return res;
    }
};

#endif /* _50_min_steps_h */
