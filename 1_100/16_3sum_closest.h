//
//  16_3sum_closest.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _6_3sum_closest_h
#define _6_3sum_closest_h

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        if(nums.size()<3)
            return 0;
        sort(nums.begin(), nums.end());
        
        int min_gap = abs(nums[0] + nums[1] + nums[2]-target);
        for(auto i=nums.begin(); i<nums.end()-2; ++i){
            auto k = nums.end()-1;
            auto j = i+1;
            
            while(j<k){
                int total = *i + *j + *k;
                int gap = abs(total-target);
                
                if(gap < min_gap){
                    min_gap = gap;
                    result = total;
                }
                
                if(total > target)
                    k--;
                else if(total < target)
                    j++;
                    
                else
                    return result;
            }
        }
        
        return result;
    }
};

#endif /* _6_3sum_closest_h */
