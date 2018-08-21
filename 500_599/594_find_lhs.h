//
//  594_find_lhs.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _94_find_lhs_h
#define _94_find_lhs_h

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        map<int, int> m;
        for (int num : nums) ++m[num];
        for (auto a : m) {
            if (m.count(a.first + 1)) {
                res = max(res, m[a.first] + m[a.first + 1]);
            }
        }
        return res;
    }
};

#endif /* _94_find_lhs_h */
