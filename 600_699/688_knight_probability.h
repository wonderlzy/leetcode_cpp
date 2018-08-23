//
//  688_knight_probability.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _88_knight_probability_h
#define _88_knight_probability_h

class Solution {
public:
    vector<vector<int>> dirs{{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> memo(K + 1, vector<vector<double>>(N, vector<double>(N, 0.0)));
        return helper(memo, N, K, r, c) / pow(8, K);
    }
    double helper(vector<vector<vector<double>>>& memo, int N, int k, int r, int c) {
        if (k == 0) return 1.0;
        if (memo[k][r][c] != 0.0) return memo[k][r][c];
        for (auto dir : dirs) {
            int x = r + dir[0], y = c + dir[1];
            if (x < 0 || x >= N || y < 0 || y >= N) continue;
            memo[k][r][c] += helper(memo, N, k - 1, x, y);
        }
        return memo[k][r][c];
    }
};

#endif /* _88_knight_probability_h */
