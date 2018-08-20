//
//  493_reverse_pair.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _93_reverse_pair_h
#define _93_reverse_pair_h

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int res = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        for (int i = left, j = mid + 1; i <= mid; ++i) {
            while (j <= right && nums[i] / 2.0 > nums[j]) ++j;
            res += j - (mid + 1);
        }
        sort(nums.begin() + left, nums.begin() + right + 1);
        return res;
    }
};

#endif /* _93_reverse_pair_h */
