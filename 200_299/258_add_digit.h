//
//  258_add_digit.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _58_add_digit_h
#define _58_add_digit_h

class Solution {
public:
    int addDigits(int num) {
        
        return (num-1)%9+1;
    }
};

#endif /* _58_add_digit_h */
