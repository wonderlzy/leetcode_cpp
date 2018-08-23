//
//  696_count_binary_subarray.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _96_count_binary_subarray_h
#define _96_count_binary_subarray_h

class Solution {
public:
    int countBinarySubstrings(string s) {
        int zeros = 0, ones = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0) {
                (s[i] == '1') ? ++ones : ++zeros;
            } else {
                if (s[i] == '1') {
                    ones = (s[i - 1] == '1') ? ones + 1 : 1;
                    if (zeros >= ones) ++res;
                } else if (s[i] == '0') {
                    zeros = (s[i - 1] == '0') ? zeros + 1 : 1;
                    if (ones >= zeros) ++res;
                }
            }
        }
        return res;
    }
};

#endif /* _96_count_binary_subarray_h */
