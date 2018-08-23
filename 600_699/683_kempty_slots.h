//
//  683_kempty_slots.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _83_kempty_slots_h
#define _83_kempty_slots_h

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int res = INT_MAX, left = 0, right = k + 1, n = flowers.size();
        vector<int> days(n, 0);
        for (int i = 0; i < n; ++i) days[flowers[i] - 1] = i + 1;
        for (int i = 0; right < n; ++i) {
            if (days[i] < days[left] || days[i] <= days[right]) {
                if (i == right) res = min(res, max(days[left], days[right]));
                left = i;
                right = k + 1 + i;
            }
        }
        return (res == INT_MAX) ? -1 : res;
    }
};

#endif /* _83_kempty_slots_h */
