//
//  803_hit_bricks.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _03_hit_bricks_h
#define _03_hit_bricks_h

class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    vector<vector<int>> g;
    int vst[201][201], id;
    int n, m;
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size(),m = grid[0].size();
        g.swap(grid);
        vector<int> ret;
        for(auto h:hits){
            int r = h[0], c = h[1];
            int removal = 0;
            if(g[r][c] == 1){
                g[r][c] = 0;
                for(int d = 0;d<4;d++){
                    int x = r+dr[d],y = c + dc[d];
                    if (!valid(x, y) || !g[x][y]) continue;
                    ++id; //mark each connecting parts with a unique id in this run
                    if(falling(x,y)) removal += cnt(x,y);
                }
            }
            ret.push_back(removal);
        }
        return ret;
    }
    bool falling(int r,int c){
        if(!valid(r,c)||!g[r][c]) return true;
        if (vst[r][c] == id) return true; //visited and belongs to the same part this run
        if (r == 0) return false; //connecting 1st row
        vst[r][c] = id;
        for (int d = 0; d < 4; ++d){
            if (!falling(r + dr[d], c + dc[d])) return false;
        }
        return true;
    }
    int cnt(int r,int c){
        if (!valid(r,c)||!g[r][c]) return 0;
        int ret = 1;
        g[r][c] = 0;
        for(int d = 0; d < 4; ++d){
            ret += cnt(r + dr[d], c + dc[d]);
        }
        return ret;
    }
    bool valid(int r,int c){
        return 0 <= r && r < n && 0 <= c && c < m;
    }
};

#endif /* _03_hit_bricks_h */
