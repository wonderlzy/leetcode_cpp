//
//  221_maximal_square.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _21_maximal_square_h
#define _21_maximal_square_h

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i == 0 || j == 0)
                    dp[i][j] = matrix[i][j]-'0';
                
                else if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
                
                res = max(res, dp[i][j]);
            }
        }
        
        
        return res*res;
    }
};

#endif /* _21_maximal_square_h */
