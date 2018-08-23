//
//  740_delete_and_earn.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _40_delete_and_earn_h
#define _40_delete_and_earn_h

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sums(10001, 0);
        int take = 0, skip = 0;
        for (int num : nums) sums[num] += num;
        for (int i = 0; i < 10001; ++i) {
            int takei = skip + sums[i];
            int skipi = max(skip, take);
            take = takei; skip = skipi;
        }
        return max(skip, take);
        
        /*
        vector<int> sums(10001, 0);
        for (int num : nums) sums[num] += num;
        for (int i = 2; i < 10001; ++i) {
            sums[i] = max(sums[i - 1], sums[i - 2] + sums[i]);
        }
        return sums[10000];
         */
    }
};

#endif /* _40_delete_and_earn_h */
