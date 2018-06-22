//
//  27_remove_element.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _7_remove_element_h
#define _7_remove_element_h

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int length = nums.size();
        int left = 0, right = length-1;
        
        while(right > left){
            while(nums[right] == val && right > left)
                --right;
            while(nums[left] != val && right > left)
                ++left;
            
            if(right > left)
                swap(nums[right--], nums[left++]);
        }
        
        return nums[left]==val ? left : left+1;
    }
};

#endif /* _7_remove_element_h */
