//
//  80_remove_duplicates.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _0_remove_duplicates_h
#define _0_remove_duplicates_h

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int index = 2;
        for(int i=2; i<nums.size(); ++i){
            if(nums[i] != nums[index-2])
                nums[index++] = nums[i];
        }
        
        return index;
    }
};

#endif /* _0_remove_duplicates_h */
