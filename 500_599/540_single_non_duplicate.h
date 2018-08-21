//
//  540_single_non_duplicate.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _40_single_non_duplicate_h
#define _40_single_non_duplicate_h

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[mid ^ 1]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};

#endif /* _40_single_non_duplicate_h */
