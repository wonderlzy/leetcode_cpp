//
//  547_splist_array.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _47_splist_array_h
#define _47_splist_array_h

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        for (int i = 1; i <= n - 5; ++i) {
            if (i != 1 && nums[i] == 0 && nums[i - 1] == 0) continue;
            for (int j = i + 2; j <= n - 3; ++j) {
                if (sums[i - 1] != (sums[j - 1] - sums[i])) continue;
                for (int k = j + 2; k <= n - 1; ++k) {
                    int sum3 = sums[k - 1] - sums[j];
                    int sum4 = sums[n - 1] - sums[k];
                    if (sum3 == sum4 && sum3 == sums[i - 1]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

#endif /* _47_splist_array_h */
