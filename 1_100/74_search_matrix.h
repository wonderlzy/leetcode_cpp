//
//  74_search_matrix.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/4.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _4_search_matrix_h
#define _4_search_matrix_h

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        if(m == 0 || n == 0) return false;
        if(matrix[0][0] > target || matrix[m-1][n-1] < target) return false;

        //search row
        int left = 0, right = m -1;
        int mid = 0, row = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] == target || matrix[mid][n-1] == target)
                return true;
            else if(matrix[mid][0] < target && matrix[mid][n-1] > target){
                row = mid;
                break;
            }
            else if(matrix[mid][0] > target)
                right = mid - 1;
            else if(matrix[mid][n-1] < target)
                left = mid + 1;
        }
        
        if(row == -1)
            return false;
        
        left = 0; right = n-1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return false;
    }
};

#endif /* _4_search_matrix_h */
