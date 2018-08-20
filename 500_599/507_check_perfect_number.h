//
//  507_check_perfect_number.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _07_check_perfect_number_h
#define _07_check_perfect_number_h

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int sum = 1;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) sum += (i + num / i);
            if (i * i == num) sum -= i;
            if (sum > num) return false;
        }
        return sum == num;
    }
};

#endif /* _07_check_perfect_number_h */
