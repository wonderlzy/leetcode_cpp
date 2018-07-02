//
//  57_insert_interval.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _7_insert_interval_h
#define _7_insert_interval_h

 // Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty()) return {newInterval};
        
        vector<Interval>::iterator iter = intervals.begin();
        while(iter != intervals.end()){
            if(newInterval.end < iter->start){
                intervals.insert(iter, newInterval);
                return intervals;
            }
            else if(newInterval.start > iter->end){
                ++iter;
                continue;
            }
            else {
                newInterval.start = min(newInterval.start, iter->start);
                newInterval.end = max(newInterval.end, iter->end);
                iter = intervals.erase(iter);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        
        return intervals;
    }
};

#endif /* _7_insert_interval_h */
