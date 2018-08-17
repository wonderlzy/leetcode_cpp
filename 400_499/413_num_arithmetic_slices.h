//
//  412_num_arithmetic_slices.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/15.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _12_num_arithmetic_slices_h
#define _12_num_arithmetic_slices_h

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, len = 2, n = A.size();
        for (int i = 2; i < n; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                ++len;
            } else {
                if (len > 2) res += (len - 1) * (len - 2) * 0.5;
                len = 2;
            }
        }
        if (len > 2) res += (len - 1) * (len - 2) * 0.5;
        return res;
    }
};

#endif /* _12_num_arithmetic_slices_h */
