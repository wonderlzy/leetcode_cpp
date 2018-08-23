//
//  728_self_dividing_numbers.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _28_self_dividing_numbers_h
#define _28_self_dividing_numbers_h

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left, n = 0; i <= right; ++i) {
            for (n = i; n > 0; n /= 10) {
                if (n % 10 == 0 || i % (n % 10) != 0) break;
            }
            if (n == 0) res.push_back(i);
        }
        return res;
    }
};

#endif /* _28_self_dividing_numbers_h */
