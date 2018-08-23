//
//  781_num_rabbits.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _81_num_rabbits_h
#define _81_num_rabbits_h

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> m;
        for (int ans : answers) {
            if (!m.count(ans + 1) || m[ans + 1] == 0) {
                res += ans + 1;
                m[ans + 1] = ans;
            } else {
                --m[ans + 1];
            }
        }
        return res;
    }
};

#endif /* _81_num_rabbits_h */
