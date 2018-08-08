//
//  296_min_total_distance.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _96_min_total_distance_h
#define _96_min_total_distance_h

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        return minTotalDistance(rows) + minTotalDistance(cols);
    }
    
    int minTotalDistance(vector<int> v) {
        int res = 0;
        sort(v.begin(), v.end());
        int i = 0, j = v.size() - 1;
        while (i < j) res += v[j--] - v[i++];
        return res;
    }
};

#endif /* _96_min_total_distance_h */
