//
//  313_nth_super_ugly_number.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _13_nth_super_ugly_number_h
#define _13_nth_super_ugly_number_h

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, 1), idx(primes.size(), 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = INT_MAX;
            for (int j = 0; j < primes.size(); ++j) {
                dp[i] = min(dp[i], dp[idx[j]] * primes[j]);
            }
            for (int j = 0; j < primes.size(); ++j) {
                if (dp[i] == dp[idx[j]] * primes[j]) {
                    ++idx[j];
                }
            }
        }
        return dp.back();
    }
};

#endif /* _13_nth_super_ugly_number_h */
