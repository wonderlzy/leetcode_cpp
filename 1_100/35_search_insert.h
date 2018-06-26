//
//  35_search_insert.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/25.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _5_search_insert_h
#define _5_search_insert_h

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0]>=target ? 0 : 1;
        
        int left = 0, right = nums.size() -1;
        while(left < right){
            int middle = left + (right-left) / 2;
            if(nums[middle] == target) return middle;
            
            else if(nums[middle] > target)
                right = middle - 1;
            
            else
                left = middle + 1;
        }
        
        return (nums[left] >= target) ? left : left+1;
    }
};

#endif /* _5_search_insert_h */
