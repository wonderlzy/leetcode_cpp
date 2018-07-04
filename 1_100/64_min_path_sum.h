//
//  64_min_path_sum.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _4_min_path_sum_h
#define _4_min_path_sum_h

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        size_t m = grid.size();
        size_t n = grid[0].size();
        vector<int> fill(n, 0);
        fill[0] = grid[0][0];
        for(int i=1; i<n; ++i)
            fill[i] = fill[i-1] + grid[0][i];
        
        for(int i=1; i<m; ++i){
            fill[0] = fill[0]+grid[i][0];
            for(int j=1; j<n; ++j){
                fill[j] = min(fill[j-1]+grid[i][j], fill[j]+grid[i][j]);
            }
        }
        
        return fill[n-1];
    }
};

#endif /* _4_min_path_sum_h */
