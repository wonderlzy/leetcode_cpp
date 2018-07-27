//
//  118_yh_generate.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/27.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _18_yh_generate_h
#define _18_yh_generate_h


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if (numRows <= 0) return res;
        res.assign(numRows, vector<int>(1));
        for (int i = 0; i < numRows; ++i) {
            res[i][0] = 1;
            if (i == 0) continue;
            for (int j = 1; j < i; ++j) {
                res[i].push_back(res[i-1][j] + res[i-1][j-1]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};

#endif /* _18_yh_generate_h */
