//
//  393_valid_utf8.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _93_valid_utf8_h
#define _93_valid_utf8_h

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int d : data) {
            if (cnt == 0) {
                if ((d >> 5) == 0b110) cnt = 1;
                else if ((d >> 4) == 0b1110) cnt = 2;
                else if ((d >> 3) == 0b11110) cnt = 3;
                else if (d >> 7) return false;
            } else {
                if ((d >> 6) != 0b10) return false;
                --cnt;
            }
        }
        return cnt == 0;
    }
};

#endif /* _93_valid_utf8_h */
