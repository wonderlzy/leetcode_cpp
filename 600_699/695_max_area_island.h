//
//  695_max_area_island.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _95_max_area_island_h
#define _95_max_area_island_h

class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                int cnt = 0;
                helper(grid, i, j, cnt, res);
            }
        }
        return res;
    }
    void helper(vector<vector<int>>& grid, int i, int j, int& cnt, int& res) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;
        res = max(res, ++cnt);
        grid[i][j] *= -1;
        for (auto dir : dirs) {
            helper(grid, i + dir[0], j + dir[1], cnt, res);
        }
    }
};

#endif /* _95_max_area_island_h */
