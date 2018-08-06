//
//  253_min_meetings_rooms.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _53_min_meetings_rooms_h
#define _53_min_meetings_rooms_h

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){return a.start < b.start;});
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto a : intervals) {
            if (!q.empty() && q.top() <= a.start) q.pop();
            q.push(a.end);
        }
        return q.size();
    }
};

#endif /* _53_min_meetings_rooms_h */
