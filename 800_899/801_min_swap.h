//
//  801_min_swap.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _01_min_swap_h
#define _01_min_swap_h

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> swap(n, n), noSwap(n, n);
        swap[0] = 1; noSwap[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                swap[i] = swap[i - 1] + 1;
                noSwap[i] = noSwap[i - 1];
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                swap[i] = min(swap[i], noSwap[i - 1] + 1);
                noSwap[i] = min(noSwap[i], swap[i - 1]);
            }
        }
        return min(swap[n - 1], noSwap[n - 1]);
    }
};

#endif /* _01_min_swap_h */
