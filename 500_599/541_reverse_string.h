//
//  541_reverse_string.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _41_reverse_string_h
#define _41_reverse_string_h

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size(), cnt = n / k;
        for (int i = 0; i <= cnt; ++i) {
            if (i % 2 == 0) {
                if (i * k + k < n) {
                    reverse(s.begin() + i * k, s.begin() + i * k + k);
                } else {
                    reverse(s.begin() + i * k, s.end());
                }
            }
        }
        return s;
    }
};

#endif /* _41_reverse_string_h */
