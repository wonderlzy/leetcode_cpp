//
//  633_judge_square_sum.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _33_judge_square_sum_h
#define _33_judge_square_sum_h

class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = sqrt(c);
        while (a <= b) {
            if (a * a + b * b == c) return true;
            else if (a * a + b * b < c) ++a;
            else --b;
        }
        return false;
    }
};

#endif /* _33_judge_square_sum_h */
