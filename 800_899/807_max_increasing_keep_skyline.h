//
//  807_max_increasing_keep_skyline.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _07_max_increasing_keep_skyline_h
#define _07_max_increasing_keep_skyline_h

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res += min(row[i] - grid[i][j], col[j] - grid[i][j]);
            }
        }
        return res;
    }
};

#endif /* _07_max_increasing_keep_skyline_h */
