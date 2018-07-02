//
//  54_rotate_array.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _4_rotate_array_h
#define _4_rotate_array_h

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        
        const int row = matrix.size();
        const int col = matrix[0].size();
        
        printEdge(matrix, result, 0, 0, row-1, col-1);
        return result;
    }
    
    void printEdge(vector<vector<int>>& matrix, vector<int>& result, int left_up_x, int left_up_y, int right_down_x, int right_down_y){
        
        if(left_up_x > right_down_x || left_up_y > right_down_y)
            return ;
        
        //top
        for(int i=left_up_y; i<=right_down_y; ++i)
            result.push_back(matrix[left_up_x][i]);
        if(left_up_x == right_down_x) return ;
        
        //right
        for(int i=left_up_x+1; i<=right_down_x; ++i)
            result.push_back(matrix[i][right_down_y]);
        if(left_up_y == right_down_y) return ;
        
        //down
        for(int i=right_down_y-1; i>=left_up_y; --i)
            result.push_back(matrix[right_down_x][i]);
        
        //left
        for(int i=right_down_x-1; i>left_up_x; --i)
            result.push_back(matrix[i][left_up_y]);
        
        printEdge(matrix, result, left_up_x+1, left_up_y+1, right_down_x-1, right_down_y-1);
    }
};

#endif /* _4_rotate_array_h */
