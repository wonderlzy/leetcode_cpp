//
//  544_find_contest_match.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _44_find_contest_match_h
#define _44_find_contest_match_h

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> v;
        for (int i = 1; i <= n; ++i) v.push_back(to_string(i));
        while (n > 1) {
            for (int i = 0; i < n / 2; ++i) {
                v[i] = "(" + v[i] + "," + v[n - i - 1] + ")";
            }
            n /= 2;
        }
        return v[0];
    }
};

#endif /* _44_find_contest_match_h */
