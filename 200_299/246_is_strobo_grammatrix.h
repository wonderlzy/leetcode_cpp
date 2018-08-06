//
//  246_is_strobo_grammatrix.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _46_is_strobo_grammatrix_h
#define _46_is_strobo_grammatrix_h

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int l = 0, r = num.size() - 1;
        while (l <= r) {
            if (num[l] == num[r]) {
                if (num[l] != '1' && num[l] != '0' && num[l] != '8'){
                    return false;
                }
            } else {
                if ((num[l] != '6' || num[r] != '9') && (num[l] != '9' || num[r] != '6')) {
                    return false;
                }
            }
            ++l; --r;
        }
        return true;
    }
};

#endif /* _46_is_strobo_grammatrix_h */
