//
//  732_my_calendar3.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _32_my_calendar3_h
#define _32_my_calendar3_h

class MyCalendarThree {
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        ++freq[start];
        --freq[end];
        int cnt = 0, mx = 0;
        for (auto f : freq) {
            cnt += f.second;
            mx = max(mx, cnt);
        }
        return mx;
    }
    
private:
    map<int, int> freq;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */

#endif /* _32_my_calendar3_h */
