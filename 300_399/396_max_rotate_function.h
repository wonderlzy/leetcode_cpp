//
//  396_max_rotate_function.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _96_max_rotate_function_h
#define _96_max_rotate_function_h

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int t = 0, sum = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            t += i * A[i];
        }
        int res = t;
        for (int i = 1; i < n; ++i) {
            t = t + sum - n * A[n - i];
            res = max(res, t);
        }
        return res;
    }
};

#endif /* _96_max_rotate_function_h */
