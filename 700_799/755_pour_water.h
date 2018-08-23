//
//  755_pour_water.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _55_pour_water_h
#define _55_pour_water_h

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int i = 0; i < V; ++i) {
            int l = K, r = K, n = heights.size();
            while (l > 0 && heights[l] >= heights[l - 1]) --l;
            while (l < K && heights[l] == heights[l + 1]) ++l;
            while (r < n - 1 && heights[r] >= heights[r + 1]) ++r;
            while (r > K && heights[r] == heights[r - 1]) --r;
            (heights[l] < heights[K]) ? ++heights[l] : ++heights[r];
        }
        return heights;
    }
};

#endif /* _55_pour_water_h */
