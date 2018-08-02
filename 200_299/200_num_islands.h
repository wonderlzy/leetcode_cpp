//
//  200_num_islands.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _00_num_islands_h
#define _00_num_islands_h

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        const size_t m = grid.size();
        const size_t n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]=='1' && !visited[i][j]){
                    numIslandsDFS(grid, visited, i, j);
                    ++res;
                }
            }
        }
        
        return res;
    }
    
private:
    void numIslandsDFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        if(x<0 || x>=grid.size()) return ;
        if(y<0 || y>=grid[0].size()) return;
        if(grid[x][y]!='1' || visited[x][y]) return ;
        
        visited[x][y] = true;
        numIslandsDFS(grid, visited, x-1, y);
        numIslandsDFS(grid, visited, x+1, y);
        numIslandsDFS(grid, visited, x, y-1);
        numIslandsDFS(grid, visited, x, y+1);
    }
};

#endif /* _00_num_islands_h */
