//
//  153_find_min.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _53_find_min_h
#define _53_find_min_h

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return 0;
        const size_t n = nums.size();
        int left = 0, right = n-1;
        
        if(nums[left] > nums[right]){
            while(left != right-1){
                int mid = left + (right - left) / 2;
                if(nums[left] > nums[mid])
                    right = mid;
                else
                    left = mid;
            }
            
            return min(nums[left], nums[right]);
        }
        
        return nums[0];
    }
};

#endif /* _53_find_min_h */
