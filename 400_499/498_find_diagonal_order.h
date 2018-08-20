//
//  498_find_diagonal_order.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _98_find_diagonal_order_h
#define _98_find_diagonal_order_h

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size(), r = 0, c = 0, k = 0;
        vector<int> res(m * n);
        vector<vector<int>> dirs{{-1,1}, {1,-1}};
        for (int i = 0; i < m * n; ++i) {
            res[i] = matrix[r][c];
            r += dirs[k][0];
            c += dirs[k][1];
            if (r >= m) {r = m - 1; c += 2; k = 1 - k;}
            if (c >= n) {c = n - 1; r += 2; k = 1 - k;}
            if (r < 0) {r = 0; k = 1 - k;}
            if (c < 0) {c = 0; k = 1 - k;}
        }
        return res;
    }
};

#endif /* _98_find_diagonal_order_h */
