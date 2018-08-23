//
//  729_my_calendar.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _29_my_calendar_h
#define _29_my_calendar_h

class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        for (auto a : cal) {
            if (max(a.first, start) < min(a.second, end)) return false;
        }
        cal.push_back({start, end});
        return true;
    }
    
private:
    vector<pair<int, int>> cal;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

#endif /* _29_my_calendar_h */
