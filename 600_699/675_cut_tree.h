//
//  675_cut_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _75_cut_tree_h
#define _75_cut_tree_h

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size(), res = 0, row = 0, col = 0;
        vector<vector<int>> trees;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());
        for (int i = 0; i < trees.size(); ++i) {
            int cnt = helper(forest, row, col, trees[i][1], trees[i][2]);
            if (cnt == -1) return -1;
            res += cnt;
            row = trees[i][1];
            col = trees[i][2];
        }
        return res;
    }
    int helper(vector<vector<int>>& forest, int row, int col, int treeRow, int treeCol) {
        if (row == treeRow && col == treeCol) return 0;
        int m = forest.size(), n = forest[0].size(), cnt = 0;
        queue<pair<int, int>> q{{{row, col}}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs{{-1,0},{0,1},{1,0},{0,-1}};
        while (!q.empty()) {
            ++cnt;
            for (int i = q.size() - 1; i >= 0; --i) {
                auto t = q.front(); q.pop();
                for (auto dir : dirs) {
                    int x = t.first + dir[0], y = t.second + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || forest[x][y] == 0) continue;
                    if (x == treeRow && y == treeCol) return cnt;
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};

#endif /* _75_cut_tree_h */
