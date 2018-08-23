//
//  699_falling_squares.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _99_falling_squares_h
#define _99_falling_squares_h

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<int> res;
        map<pair<int, int>, int> m;
        int curMax = 0;
        for (auto &pos : positions) {
            vector<vector<int>> t;
            int len = pos.second, start = pos.first, end = start + len, h = 0;
            auto it = m.upper_bound({start, start});
            if (it != m.begin() && (--it)->first.second <= start) ++it;
            while (it != m.end() && it->first.first < end) {
                if (start > it->first.first) t.push_back({it->first.first, start, it->second});
                if (end < it->first.second) t.push_back({end, it->first.second, it->second});
                h = max(h, it->second);
                it = m.erase(it);
            }
            m[{start, end}] = h + len;
            for (auto &a : t) m[{a[0], a[1]}] = a[2];
            curMax = max(curMax, h + len);
            res.push_back(curMax);
        }
        return res;
    }
};

#endif /* _99_falling_squares_h */
