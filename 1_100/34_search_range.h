//
//  34_search_range.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/25.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _4_search_range_h
#define _4_search_range_h

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int left = 0, right = nums.size()-1;
        vector<int> result;
        
        while(left<right){
            int middle = left + (right - left) / 2;
            if(target == nums[middle]){
                left = middle;
                right = middle;
                while(nums[right] == target && right<nums.size()) ++right;
                while(nums[left] == target && left>=0) --left;
                return {left+1, right-1};
            }
            
            else if(target < nums[middle])
                right = middle - 1;
            else left = middle + 1;
        }
        
        if(nums[left] == target){
            result.push_back(left);
            result.push_back(left);
            return result;
        }
        
        return  {-1, -1};
    }
};

#endif /* _4_search_range_h */
