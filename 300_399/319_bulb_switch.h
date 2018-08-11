//
//  319_bulb_switch.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _19_bulb_switch_h
#define _19_bulb_switch_h

class Solution {
public:
    int bulbSwitch(int n) {
        /*
        int res = 1;
        while(res*res <= n)
            ++res;
        
        return res-1;
        */
        return sqrt(n);
    }
};

#endif /* _19_bulb_switch_h */
