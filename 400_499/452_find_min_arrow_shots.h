//
//  452_find_min_arrow_shots.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _52_find_min_arrow_shots_h
#define _52_find_min_arrow_shots_h

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end());
        int res = 1, end = points[0].second;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i].first <= end) {
                end = min(end, points[i].second);
            } else {
                ++res;
                end = points[i].second;
            }
        }
        return res;
    }
};

#endif /* _52_find_min_arrow_shots_h */
