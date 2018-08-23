//
//  795_num_subarray_bouned_max.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _95_num_subarray_bouned_max_h
#define _95_num_subarray_bouned_max_h

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, left = -1, right = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R) left = i;
            if (A[i] >= L) right = i;
            res += right - left;
        }
        return res;
    }
};

#endif /* _95_num_subarray_bouned_max_h */
