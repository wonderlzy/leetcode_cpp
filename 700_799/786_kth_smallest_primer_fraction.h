//
//  786_kth_smallest_primer_fraction.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _86_kth_smallest_primer_fraction_h
#define _86_kth_smallest_primer_fraction_h

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double left = 0, right = 1;
        int p = 0, q = 1, cnt = 0, n = A.size();
        while (true) {
            double mid = left + (right - left) / 2.0;
            cnt = 0; p = 0;
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && A[i] > mid * A[j]) ++j;
                cnt += n - j;
                if (j < n && p * A[j] < q * A[i]) {
                    p = A[i];
                    q = A[j];
                }
            }
            if (cnt == K) return {p, q};
            else if (cnt < K) left = mid;
            else right = mid;
        }
    }
};

#endif /* _86_kth_smallest_primer_fraction_h */
