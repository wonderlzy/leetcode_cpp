//
//  81_rotate_sort_array.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _1_rotate_sort_array_h
#define _1_rotate_sort_array_h

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int first = 0, last = nums.size()-1;
        while(first <= last){
            const int mid = first + (last - first) / 2;
            if(nums[mid] == target) return true;
            
            if(nums[first] < nums[mid]){
                if(target >= nums[first] && target < nums[mid])
                    last = mid - 1;
                else first = mid + 1;
            } else if(nums[first] > nums[mid]){
                if(target > nums[mid] && target <= nums[last])
                    first = mid + 1;
                else last = mid - 1;
            } else
                ++first;
        }
        
        return false;
    }
};

#endif /* _1_rotate_sort_array_h */
