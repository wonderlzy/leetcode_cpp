//
//  263_is_ugly.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _63_is_ugly_h
#define _63_is_ugly_h

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
};

#endif /* _63_is_ugly_h */
