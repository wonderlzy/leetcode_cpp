//
//  170_two_sum3.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _70_two_sum3_h
#define _70_two_sum3_h

class TwoSum {
public:
    void add(int number) {
        ++m[number];
    }
    bool find(int value) {
        for (auto a : m) {
            int t = value - a.first;
            if ((t != a.first && m.count(t)) || (t == a.first && a.second > 1)) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_map<int, int> m;
};

#endif /* _70_two_sum3_h */
