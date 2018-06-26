//
//  33_search_rotate_arr.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/25.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _3_search_rotate_arr_h
#define _3_search_rotate_arr_h

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        int first = 0, last = nums.size();
        
        while(first != last){
            int middle = (last - first) / 2 + first;
            if(nums[middle] == target) return middle;
            
            if(nums[first] <= nums[middle]){
                if(nums[first] <= target && nums[middle] > target)
                    last = middle;
                else
                    first = middle + 1;
            } else {
                if(nums[middle]<target && nums[last-1]>=target)
                    first = middle + 1;
                else
                    last = middle;
            }
        }
        
        return -1;
        */
        return searchRange(nums, 0, nums.size()-1, target);
    }
    
    int searchRange(vector<int>& nums, int left, int right, int target){
        if(right<left) return -1;
        if(left == right) return nums[left]==target ? left : -1;
        int middle = left + (right-left) / 2;
        if(nums[middle] == target) return middle;
        
        if(nums[middle] >= nums[left]){ // left is ordered
            if(nums[middle]>target && nums[left]<=target)
                return searchRange(nums, left, middle-1, target);
            else return searchRange(nums, middle+1, right, target);
        }
        else { // right is ordered
            if(nums[middle]<target && nums[right]>=target)
                return searchRange(nums, middle+1, right, target);
            else return searchRange(nums, left, middle-1, target);
        }
    }
};

#endif /* _3_search_rotate_arr_h */
