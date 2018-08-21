//
//  554_least_bricks.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _54_least_bricks_h
#define _54_least_bricks_h

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int mx = 0;
        unordered_map<int, int> m;
        for (auto a : wall) {
            int sum = 0;
            for (int i = 0; i < a.size() - 1; ++i) {
                sum += a[i];
                ++m[sum];
                mx = max(mx, m[sum]);
            }
        }
        return wall.size() - mx;
    }
};

#endif /* _54_least_bricks_h */
