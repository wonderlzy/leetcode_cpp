//
//  356_is_reflected.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _56_is_reflected_h
#define _56_is_reflected_h

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int, set<int>> m;
        int mx = INT_MIN, mn = INT_MAX;
        for (auto a : points) {
            mx = max(mx, a.first);
            mn = min(mn, a.first);
            m[a.first].insert(a.second);
        }
        double y = (double)(mx + mn) / 2;
        for (auto a : points) {
            int t = 2 * y - a.first;
            if (!m.count(t) || !m[t].count(a.second)) {
                return false;
            }
        }
        return true;
    }
}; 

#endif /* _56_is_reflected_h */
