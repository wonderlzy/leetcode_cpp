//
//  567_check_inclusion.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _67_check_inclusion_h
#define _67_check_inclusion_h

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> m1(128), m2(128);
        for (int i = 0; i < n1; ++i) {
            ++m1[s1[i]]; ++m2[s2[i]];
        }
        if (m1 == m2) return true;
        for (int i = n1; i < n2; ++i) {
            ++m2[s2[i]];
            --m2[s2[i - n1]];
            if (m1 == m2) return true;
        }
        return false;
    }
};

#endif /* _67_check_inclusion_h */
