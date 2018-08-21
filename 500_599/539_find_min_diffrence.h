//
//  539_find_min_diffrence.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _39_find_min_diffrence_h
#define _39_find_min_diffrence_h

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX, n = timePoints.size(), diff = 0;
        if(n>1440) return 0;
        
        sort(timePoints.begin(), timePoints.end());
        for (int i = 0; i < n; ++i) {
            string t1 = timePoints[i], t2 = timePoints[(i + 1) % n];
            int h1 = (t1[0] - '0') * 10 + t1[1] - '0';
            int m1 = (t1[3] - '0') * 10 + t1[4] - '0';
            int h2 = (t2[0] - '0') * 10 + t2[1] - '0';
            int m2 = (t2[3] - '0') * 10 + t2[4] - '0';
            diff = (h2 - h1) * 60 + (m2 - m1);
            if (i == n - 1) diff += 24 * 60;
            res = min(res, diff);
        }
        return res;
    }
};

#endif /* _39_find_min_diffrence_h */
