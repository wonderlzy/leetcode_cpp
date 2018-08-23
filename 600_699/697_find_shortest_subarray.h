//
//  697_find_shortest_subarray.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _97_find_shortest_subarray_h
#define _97_find_shortest_subarray_h

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), res = INT_MAX, degree = 0;
        unordered_map<int, int> m;
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < nums.size(); ++i) {
            if (++m[nums[i]] == 1) {
                pos[nums[i]] = {i, i};
            } else {
                pos[nums[i]].second = i;
            }
            degree = max(degree, m[nums[i]]);
        }
        for (auto a : m) {
            if (degree == a.second) {
                res = min(res, pos[a.first].second - pos[a.first].first + 1);
            }
        }
        return res;
    }
};

#endif /* _97_find_shortest_subarray_h */
