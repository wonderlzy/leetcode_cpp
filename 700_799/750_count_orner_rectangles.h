//
//  750_count_orner_rectangles.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _50_count_orner_rectangles_h
#define _50_count_orner_rectangles_h

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int cnt = 0;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] == 1 && grid[j][k] == 1) ++cnt;
                }
                res += cnt * (cnt - 1) / 2;
            }
        }
        return res;
    }
};

#endif /* _50_count_orner_rectangles_h */
