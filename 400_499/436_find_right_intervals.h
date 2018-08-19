//
//  436_find_right_intervals.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _36_find_right_intervals_h
#define _36_find_right_intervals_h

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> res, v;
        unordered_map<int, int> m;
        for (int i = 0; i < intervals.size(); ++i) {
            m[intervals[i].start] = i;
            v.push_back(intervals[i].start);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (auto a : intervals) {
            int i = 0;
            for (; i < v.size(); ++i) {
                if (v[i] < a.end) break;
            }
            res.push_back((i > 0) ? m[v[i - 1]] : -1);
        }
        return res;
    }
};

#endif /* _36_find_right_intervals_h */
