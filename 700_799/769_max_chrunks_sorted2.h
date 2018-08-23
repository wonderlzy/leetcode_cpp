//
//  769_max_chrunks_sorted2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _69_max_chrunks_sorted2_h
#define _69_max_chrunks_sorted2_h

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, n = arr.size(), mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, arr[i]);
            if (mx == i) ++res;
        }
        return res;
    }
};

#endif /* _69_max_chrunks_sorted2_h */
