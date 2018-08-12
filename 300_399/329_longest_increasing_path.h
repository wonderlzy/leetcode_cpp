//
//  329_longest_increasing_path.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _29_longest_increasing_path_h
#define _29_longest_increasing_path_h

class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        
        return res;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j){
        if(dp[i][j]) return dp[i][j];
        int res = 1, m = matrix.size(), n = matrix[0].size();
        
        for(auto dir : dirs){
            int x = i + dir[0], y = j + dir[1];
            if(x<0 || x>=m || y<0 || y>=n || matrix[x][y]<=matrix[i][j])
                continue;
            int len = 1 + dfs(matrix, dp, x, y);
            res = max(res, len);
        }
        
        dp[i][j] = res;
        return res;
    }
};

#endif /* _29_longest_increasing_path_h */
