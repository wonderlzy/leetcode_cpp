//
//  624_max_distance.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _24_max_distance_h
#define _24_max_distance_h

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, start = arrays[0][0], end = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            res = max(res, max(abs(arrays[i].back() - start), abs(end - arrays[i][0])));
            start = min(start, arrays[i][0]);
            end = max(end, arrays[i].back());
        }
        return res;
    }
};

#endif /* _24_max_distance_h */
