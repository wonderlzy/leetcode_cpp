//
//  507_find_relative_ranks.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _07_find_relative_ranks_h
#define _07_find_relative_ranks_h

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size(), cnt = 1;
        vector<string> res(n, "");
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[nums[i]] = i;
        }
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            if (cnt == 1) res[it->second] = "Gold Medal";
            else if (cnt == 2) res[it->second] = "Silver Medal";
            else if (cnt == 3) res[it->second] = "Bronze Medal";
            else res[it->second] = to_string(cnt);
            ++cnt;
        }
        return res;
    }
};

#endif /* _07_find_relative_ranks_h */
