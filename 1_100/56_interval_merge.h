//
//  56_interval_merge.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _6_interval_merge_h
#define _6_interval_merge_h

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return intervals;
        
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
            return a.start < b.start;
        });
        
        Interval last = intervals[0];
        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i].start >= last.start && intervals[i].start <= last.end){
                intervals[i].start = last.start;
                intervals[i].end = last.end>=intervals[i].end ? last.end : intervals[i].end;
            }
            else result.push_back(last);
            
            last = intervals[i];
        }
        result.push_back(last);
        
        return result;
        
        /*
        if(intervals.size() <=1) return intervals;
        vector<Interval> result;
        for(auto intval : intervals)
            insert(result, intval);
        return result;
        */
        /*
         if(intervals.size() <=1) return intervals;
        
        vector<Interval> result;
        map<int, Interval, less<int>> key_value;
        for_each(intervals.begin(), intervals.end(), [&key_value](Interval inter){
            if(key_value.find(inter.start) != key_value.end())
                key_value[inter.start].end = inter.end>key_value[inter.start].end ? inter.end : key_value[inter.start].end;
            else key_value[inter.start] = inter;
        });
        
        map<int, Interval, less<int>>::iterator iter = key_value.begin();
        Interval cur = iter->second;
        
        for(iter = next(iter, 1); iter!=key_value.end(); ++iter){
            if(iter->second.start <= cur.end)
                cur.end = iter->second.end > cur.end ? iter->second.end : cur.end;
            else{
                result.push_back(cur);
                cur = iter->second;
            }
        }
        
        result.push_back(cur);
        
        return result;
        */
    }
private:
    vector<Interval> insert(vector<Interval>& result, Interval newInterval){
        vector<Interval>::iterator iter = result.begin();
        while(iter != result.end()){
            if(newInterval.end < iter->start){
                result.insert(iter, newInterval);
                return result;
            }
            else if(newInterval.start > iter->end){
                ++iter;
                continue;
            }
            else{
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
                iter = result.erase(iter);
            }
        }
        
        result.insert(result.end(), newInterval);
        
        return result;
    }
    
};

#endif /* _6_interval_merge_h */
