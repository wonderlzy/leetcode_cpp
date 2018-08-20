//
//  441_arrange_coins.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _41_arrange_coins_h
#define _41_arrange_coins_h

class Solution {
public:
    int arrangeCoins(int n) {
        /*
        int cur = 1, rem = n - 1;
        while (rem >= cur + 1) {
            ++cur;
            rem -= cur;
        }
        return n == 0 ? 0 : cur;
        */
        return (int)((-1 + sqrt(1 + 8 * (long)n)) / 2);
    }
};

#endif /* _41_arrange_coins_h */
