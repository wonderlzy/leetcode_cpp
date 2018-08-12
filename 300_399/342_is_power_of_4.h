//
//  342_is_power_of_4.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _42_is_power_of_4_h
#define _42_is_power_of_4_h

class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num && num % 4 == 0){
            num /= 4;
        }
        return num == 1;
        /*
        return num>0 && int(log10(num)/log10(4)) - log10(num)/log10(4)==0;
        */
    }
};

#endif /* _42_is_power_of_4_h */
