//
//  154_find_min2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _54_find_min2_h
#define _54_find_min2_h

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        const size_t n = nums.size();
        int left = 0, right = n-1;
        int res = nums[0];
        while (left < right -1) {
            int mid = left + (right - left) / 2;
            if(nums[left] < nums[mid]){
                res = min(res, nums[left]);
                left = mid+1;
            }
            else if(nums[left] > nums[mid]){
                res = min(res, nums[mid]);
                right = mid;
            } else
                ++left;
        }
        
        res = min(res, nums[left]);
        res = min(res, nums[right]);
        
        return res;
    }
};

#endif /* _54_find_min2_h */
