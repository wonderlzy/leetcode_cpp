//
//  651_max_A.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _51_max_A_h
#define _51_max_A_h

class Solution {
public:
    int maxA(int N) {
        int res = N;
        for (int i = 1; i < N - 2; ++i) {
            res = max(res, maxA(i) * (N - 1 - i));
        }
        return res;
    }
};

#endif /* _51_max_A_h */
