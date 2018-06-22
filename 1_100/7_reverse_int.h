//
//  7_reverse_int.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/11.
//  Copyright © 2018年 zhongyingli. All rights reserved.
//

#ifndef __reverse_int_h
#define __reverse_int_h

class Solution {
public:
    int reverse(int x) {
        long long r = 0;
        long long t = x;
        long long max_int = ~(1<<31);
        t = t > 0 ? t : -t;
        
        for (; t; t /= 10)
            r = r * 10 + t % 10;
        
        bool sign = x > 0 ? false: true;
        if (r > max_int || (sign && r > max_int+1))
            return 0;
        else
            return sign ? -r : r;
    }
};

#endif /* __reverse_int_h */
