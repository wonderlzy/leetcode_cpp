//
//  73_set_matric_zero.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/4.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _3_set_matric_zero_h
#define _3_set_matric_zero_h

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        
        bool row_has_zero = false, col_has_zero = false;
        
        for(int i=0; i<n; ++i)
            if(matrix[0][i] == 0){
                row_has_zero = true;
                break;
            }
        
        for(int j=0; j<m; ++j)
            if(matrix[j][0] == 0){
                col_has_zero = true;
                break;
            }
        
        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        
        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j] = 0;
        
        if(row_has_zero)
            for(int j=0; j<n; ++j)
                matrix[0][j] = 0;
        
        if(col_has_zero)
            for(int i=0; i<m; ++i)
                matrix[i][0] = 0;
        
        return ;
    }
};

#endif /* _3_set_matric_zero_h */
