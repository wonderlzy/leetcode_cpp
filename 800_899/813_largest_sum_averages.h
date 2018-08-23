//
//  813_largest_sum_averages.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _13_largest_sum_averages_h
#define _13_largest_sum_averages_h

class Solution {
public:
    double memo[200][200];
    double largestSumOfAverages(vector<int>& A, int K) {
        memset(memo, 0, sizeof(memo));
        int N = A.size();
        double cur = 0;
        for (int i = 0; i < N; ++i) {
            cur += A[i];
            memo[i + 1][1] = cur / (i + 1);
        }
        return search(N, K, A);
    }
    
    double search(int n, int k, vector<int>& A) {
        if (memo[n][k] > 0) return memo[n][k];
        if (n < k) return 0; // 14ms to 10ms
        double cur = 0;
        for (int i = n - 1; i > 0; --i) {
            cur += A[i];
            memo[n][k] = max(memo[n][k], search(i, k - 1, A) + cur / (n - i));
        }
        return memo[n][k];
    }
};

#endif /* _13_largest_sum_averages_h */
