//
//  738_monotone_increasing_digits.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _38_monotone_increasing_digits_h
#define _38_monotone_increasing_digits_h

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int n = str.size(), j = n;
        for (int i = n - 1; i > 0; --i) {
            if (str[i] >= str[i - 1]) continue;
            --str[i - 1];
            j = i;
        }
        for (int i = j; i < n; ++i) {
            str[i] = '9';
        }
        return stoi(str);
    }
};

#endif /* _38_monotone_increasing_digits_h */
