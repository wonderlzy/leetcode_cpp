//
//  240_search_matrix.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _40_search_matrix_h
#define _40_search_matrix_h

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        if(target < matrix[0][0] || target > matrix.back().back())
            return false;
        
        int x = matrix.size()-1, y = 0;
        while (true) {
            if(matrix[x][y] > target) --x;
            else if(matrix[x][y] < target) ++y;
            else return true;
            if(x < 0 || y >= matrix[0].size())
                break;
        }
        
        return false;
    }
};

#endif /* _40_search_matrix_h */
