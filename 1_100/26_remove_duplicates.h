//
//  26_remove_duplicates.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _6_remove_duplicates_h
#define _6_remove_duplicates_h

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

#endif /* _6_remove_duplicates_h */
