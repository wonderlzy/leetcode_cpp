//
//  686_repeated_string_match.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _86_repeated_string_match_h
#define _86_repeated_string_match_h

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n1 = A.size(), n2 = B.size(), cnt = 1;
        string t = A;
        while (t.size() < n2) {
            t += A;
            ++cnt;
        }
        if (t.find(B) != string::npos) return cnt;
        t += A;
        return (t.find(B) != string::npos) ? cnt + 1 : -1;
    }
};

#endif /* _86_repeated_string_match_h */
