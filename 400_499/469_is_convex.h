//
//  469_is_convex.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _69_is_convex_h
#define _69_is_convex_h

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        long long n = points.size(), pre = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            int dx1 = points[(i + 1) % n][0] - points[i][0];
            int dx2 = points[(i + 2) % n][0] - points[i][0];
            int dy1 = points[(i + 1) % n][1] - points[i][1];
            int dy2 = points[(i + 2) % n][1] - points[i][1];
            cur = dx1 * dy2 - dx2 * dy1;
            if (cur != 0) {
                if (cur * pre < 0) return false;
                else pre = cur;
            }
        }
        return true;
    }
};

#endif /* _69_is_convex_h */
