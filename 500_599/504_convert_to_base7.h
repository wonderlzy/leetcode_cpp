//
//  505_convert_to_base7.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _05_convert_to_base7_h
#define _05_convert_to_base7_h

class Solution {
public:
    string convertToBase7(int num) {
        if (num < 0) return "-" + convertToBase7(-num);
        if (num < 7) return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
        
        /*
        if (num == 0) return "0";
        string res = "";
        bool positive = num > 0;
        while (num != 0) {
            res = to_string(abs(num % 7)) + res;
            num /= 7;
        }
        return positive ? res : "-" + res;
        */
    }
};

#endif /* _05_convert_to_base7_h */
