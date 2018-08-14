//
//  405_to_hex.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _05_to_hex_h
#define _05_to_hex_h

class Solution {
public:
    string toHex(int num) {
        string res = "", str = "0123456789abcdef";
        int cnt = 0;
        while (num != 0 && cnt++ < 8) {
            res = str[(num & 0xf)] + res;
            num >>= 4;
        }
        return res.empty() ? "0" : res;
    }
};

#endif /* _05_to_hex_h */
