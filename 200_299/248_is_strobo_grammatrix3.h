//
//  248_is_strobo_grammatrix3.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _48_is_strobo_grammatrix3_h
#define _48_is_strobo_grammatrix3_h

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        for (int i = low.size(); i <= high.size(); ++i) {
            find(low, high, "", i, res);
            find(low, high, "0", i, res);
            find(low, high, "1", i, res);
            find(low, high, "8", i, res);
        }
        return res;
    }
    void find(string low, string high, string path, int len, int &res) {
        if (path.size() >= len) {
            if (path.size() != len || (len != 1 && path[0] == '0')) return;
            if ((len == low.size() && path.compare(low) < 0) || (len == high.size() && path.compare(high) > 0)) {
                return;
            }
            ++res;
        }
        find(low, high, "0" + path + "0", len, res);
        find(low, high, "1" + path + "1", len, res);
        find(low, high, "6" + path + "9", len, res);
        find(low, high, "8" + path + "8", len, res);
        find(low, high, "9" + path + "6", len, res);
    }
};

#endif /* _48_is_strobo_grammatrix3_h */
