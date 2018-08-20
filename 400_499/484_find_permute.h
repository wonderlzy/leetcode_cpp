//
//  484_find_permute.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _84_find_permute_h
#define _84_find_permute_h

class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res;
        for (int i = 0; i < s.size() + 1; ++i) {
            if (i == s.size() || s[i] == 'I') {
                int size = res.size();
                for (int j = i + 1; j > size; --j) {
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};

#endif /* _84_find_permute_h */
