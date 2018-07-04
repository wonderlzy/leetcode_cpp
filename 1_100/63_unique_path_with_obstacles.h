//
//  63_unique_path_with_obstacles.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _3_unique_path_with_obstacles_h
#define _3_unique_path_with_obstacles_h

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) return -1;
        size_t m = obstacleGrid.size();
        size_t n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        
        vector<int> fill(n, 0);
        fill[0] = 1;
        for(int i=0; i<m; ++i){
            for(int j=1; j<n; ++j){
                fill[0] = (obstacleGrid[i][0]==1 || fill[0] == 0) ? 0 : 1;
                if(!obstacleGrid[i][j])
                    fill[j] = fill[j] + fill[j-1];
                else fill[j] = 0;
            }
        }
        
        return fill[n-1];
    }
};

#endif /* _3_unique_path_with_obstacles_h */
