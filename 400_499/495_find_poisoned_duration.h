//
//  495_find_poisoned_duration.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _95_find_poisoned_duration_h
#define _95_find_poisoned_duration_h

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int res = 0, n = timeSeries.size();
        for (int i = 1; i < n; ++i) {
            int diff = timeSeries[i] - timeSeries[i - 1];
            res += (diff < duration) ? diff : duration;
        }
        return res + duration;
    }
};

#endif /* _95_find_poisoned_duration_h */
