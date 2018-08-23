//
//  670_maximum_swap.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _70_maximum_swap_h
#define _70_maximum_swap_h

class Solution {
public:
    int maximumSwap(int num) {
        string res = to_string(num), back = res;
        for (int i = back.size() - 2; i >= 0; --i) {
            back[i] = max(back[i], back[i + 1]);
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == back[i]) continue;
            for (int j = res.size() - 1; j > i; --j) {
                if (res[j] == back[i]) {
                    swap(res[i], res[j]);
                    return stoi(res);
                }
            }
        }
        return stoi(res);
    }
};

#endif /* _70_maximum_swap_h */
