//
//  497_random_point_rect.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _97_random_point_rect_h
#define _97_random_point_rect_h

class Solution {
public:
    vector<int> v;
    vector<vector<int>> rects;
    
    int area(vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
    
    Solution(vector<vector<int>> _) {
        rects = _;
        for (auto& r : rects) {
            v.push_back(area(r) + (v.empty() ? 0 : v.back()));
        }
    }
    
    vector<int> pick() {
        int rnd = rand() % v.back();
        auto it = upper_bound(v.begin(), v.end(), rnd);
        int idx = it - v.begin();
        
        // pick a random point in rect[idx]
        auto r = rects[idx];
        return {
            rand() % (r[2] - r[0] + 1) + r[0],
            rand() % (r[3] - r[1] + 1) + r[1]
        };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */

#endif /* _97_random_point_rect_h */
