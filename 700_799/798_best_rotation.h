//
//  798_best_rotation.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _98_best_rotation_h
#define _98_best_rotation_h

class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size(), res = 0;
        vector<int> change(n, 0);
        for (int i = 0; i < n; ++i) change[(i - A[i] + 1 + n) % n] -= 1;
        for (int i = 1; i < n; ++i) {
            change[i] += change[i - 1] + 1;
            res = (change[i] > change[res]) ? i : res;
        }
        return res;
    }
};

#endif /* _98_best_rotation_h */
