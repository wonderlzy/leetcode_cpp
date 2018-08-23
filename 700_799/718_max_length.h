//
//  718_max_length.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _18_max_length_h
#define _18_max_length_h

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

#endif /* _18_max_length_h */
