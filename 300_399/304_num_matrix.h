//
//  304_num_matrix.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _04_num_matrix_h
#define _04_num_matrix_h

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty())
            return ;
        dp.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        
        for(int i=1; i<=matrix.size(); ++i)
            for(int j=1; j<=matrix[0].size(); ++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        return dp[row2+1][col2+1]-dp[row2+1][col1]-dp[row1][col2+1]+dp[row1][col1];
    }
private:
    vector<vector<int>> dp;
};

#endif /* _04_num_matrix_h */
