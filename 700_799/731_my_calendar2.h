//
//  731_my_calendar2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _31_my_calendar2_h
#define _31_my_calendar2_h

class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        ++freq[start];
        --freq[end];
        int cnt = 0;
        for (auto f : freq) {
            cnt += f.second;
            if (cnt == 3) {
                --freq[start];
                ++freq[end];
                return false;
            }
        }
        return true;
    }
    
private:
    map<int, int> freq;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */

#endif /* _31_my_calendar2_h */
