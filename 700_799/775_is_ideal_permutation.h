//
//  775_is_ideal_permutation.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _75_is_ideal_permutation_h
#define _75_is_ideal_permutation_h

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size(), mn = INT_MAX;
        for (int i = n - 1; i >= 2; --i) {
            mn = min(mn, A[i]);
            if (A[i - 2] > mn) return false;
        }
        return true;
    }
};

#endif /* _75_is_ideal_permutation_h */
