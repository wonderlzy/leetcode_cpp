//
//  823_number_factored_binary_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _23_number_factored_binary_tree_h
#define _23_number_factored_binary_tree_h

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        long res = 0, mod = pow(10, 9) + 7;
        sort(A.begin(), A.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j)
                if (A[i] % A[j] == 0 && dp.count(A[i] / A[j]) == 1)
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
        }
        for (auto &it : dp) res = (res + it.second) % mod;
        return res;
    }
};

#endif /* _23_number_factored_binary_tree_h */
