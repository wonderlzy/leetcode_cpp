//
//  598_max_count.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _98_max_count_h
#define _98_max_count_h

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};

#endif /* _98_max_count_h */
