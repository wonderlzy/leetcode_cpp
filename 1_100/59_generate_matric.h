//
//  59_generate_matric.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _9_generate_matric_h
#define _9_generate_matric_h

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        if(n<=1) return {{1}};
        //
        result.resize(n);
        for(int row = 0; row < n; ++row)
            result[row].resize(n);
        
        int leftX = 0, leftY = 0;
        int rightX = n-1, rightY = n-1;
        int fill_num = 1;
        for(int i=0; i<n/2; ++i){
            //up
            for(int j=0; j<n-2*i; ++j)
                result[leftX][leftY+j] = fill_num++;
            
            //right
            for(int j=1; j<n-2*i; ++j)
                result[leftX+j][rightY] = fill_num++;
            
            //bottom
            for(int j=n-2*i-2; j>=0; --j)
                result[rightX][leftY+j] = fill_num++;
            
            //left
            for(int j=n-2*i-2; j>0; --j)
                result[leftX+j][leftY] = fill_num++;
            
            leftX++;
            leftY++;
            rightX--;
            rightY--;
        }
        
        if(n%2 == 1) result[leftX][leftY] = fill_num;
        
        return result;
    }
};

#endif /* _9_generate_matric_h */
