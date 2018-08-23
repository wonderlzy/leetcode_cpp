//
//  749_contain_virus.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _49_contain_virus_h
#define _49_contain_virus_h

class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs{{-1,0},{0,1},{1,0},{0,-1}};
        while (true) {
            unordered_set<int> visited;
            vector<vector<vector<int>>> all;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1 && !visited.count(i * n + j)) {
                        queue<int> q{{i * n + j}};
                        vector<int> virus{i * n + j};
                        vector<int> walls;
                        visited.insert(i * n + j);
                        while (!q.empty()) {
                            auto t = q.front(); q.pop();
                            for (auto dir : dirs) {
                                int x = (t / n) + dir[0], y = (t % n) + dir[1];
                                if (x < 0 || x >= m || y < 0 || y >= n || visited.count(x * n + y)) continue;
                                if (grid[x][y] == -1) continue;
                                else if (grid[x][y] == 0) walls.push_back(x * n + y);
                                else if (grid[x][y] == 1) {
                                    visited.insert(x * n + y);
                                    virus.push_back(x * n + y);
                                    q.push(x * n + y);
                                }
                            }
                        }
                        unordered_set<int> s(walls.begin(), walls.end());
                        vector<int> cells{(int)s.size()};
                        all.push_back({cells ,walls, virus});
                    }
                }
            }
            if (all.empty()) break;
            sort(all.begin(), all.end(), [](vector<vector<int>> &a, vector<vector<int>> &b) {return a[0][0] > b[0][0];});
            for (int i = 0; i < all.size(); ++i) {
                if (i == 0) {
                    vector<int> virus = all[0][2];
                    for (int idx : virus) grid[idx / n][idx % n] = -1;
                    res += all[0][1].size();
                } else {
                    vector<int> wall = all[i][1];
                    for (int idx : wall) grid[idx / n][idx % n] = 1;
                }
            }
        }
        return res;
    }
};

#endif /* _49_contain_virus_h */
