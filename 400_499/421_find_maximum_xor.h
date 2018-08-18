//
//  421_find_maximum_xor.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/17.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _21_find_maximum_xor_h
#define _21_find_maximum_xor_h

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int t = res | (1 << i);
            for (int prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};

#endif /* _21_find_maximum_xor_h */
