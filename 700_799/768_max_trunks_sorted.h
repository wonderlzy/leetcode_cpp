//
//  768_max_trunks_sorted.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _68_max_trunks_sorted_h
#define _68_max_trunks_sorted_h

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 1, n = arr.size();
        vector<int> f = arr, b = arr;
        for (int i = 1; i < n; ++i) f[i] = max(arr[i], f[i - 1]);
        for (int i = n - 2; i >= 0; --i) b[i] = min(arr[i], b[i + 1]);
        for (int i = 0; i < n - 1; ++i) {
            if (f[i] <= b[i + 1]) ++res;
        }
        return res;
    }
};

#endif /* _68_max_trunks_sorted_h */
