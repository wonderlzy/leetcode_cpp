//
//  581_find_unsorted_subarray.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _81_find_unsorted_subarray_h
#define _81_find_unsorted_subarray_h

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1;
        vector<int> t = nums;
        sort(t.begin(), t.end());
        while (i < n && nums[i] == t[i]) ++i;
        while (j > i && nums[j] == t[j]) --j;
        return j - i + 1;
    }
};

#endif /* _81_find_unsorted_subarray_h */
