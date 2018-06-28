//
//  48_rotate_image.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/28.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _8_rotate_image_h
#define _8_rotate_image_h

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for(int i=0; i<n; ++i)
            for(int j=0; j<n-i; ++j)
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        
        for(int i=0; i<n/2; i++)
            for(int j=0; j<n; ++j)
                swap(matrix[i][j], matrix[n-i-1][j]);
        
        return ;
    }
};

#endif /* _8_rotate_image_h */
