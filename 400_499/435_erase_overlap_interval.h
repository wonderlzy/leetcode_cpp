//
//  435_erase_overlap_interval.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _35_erase_overlap_interval_h
#define _35_erase_overlap_interval_h

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include "../base_structure.h"
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int res = 0, n = intervals.size(), last = 0;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
            return a.start < b.start;
        });
        
        for(int i=1; i<n; ++i){
            if(intervals[i].start < intervals[last].end){
                ++res;
                if(intervals[i].end < intervals[last].end)
                    last = i;
            } else {
                last = i;
            }
        }
        
        return res;
    }
};

#endif /* _35_erase_overlap_interval_h */
