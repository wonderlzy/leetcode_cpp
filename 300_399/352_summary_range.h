//
//  352_summary_range.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _52_summary_range_h
#define _52_summary_range_h

#include "../base_structure.h"

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        Interval cur(val, val);
        vector<Interval> res;
        int pos = 0;
        for (auto a : v) {
            if (cur.end + 1 < a.start) {
                res.push_back(a);
            } else if (cur.start > a.end + 1) {
                res.push_back(a);
                ++pos;
            } else {
                cur.start = min(cur.start, a.start);
                cur.end = max(cur.end, a.end);
            }
        }
        res.insert(res.begin() + pos, cur);
        v = res;
    }
    
    vector<Interval> getIntervals() {
        return v;
    }
    
private:
    vector<Interval> v;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

#endif /* _52_summary_range_h */
