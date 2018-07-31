//
//  162_find_peek_element.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _62_find_peek_element_h
#define _62_find_peek_element_h

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) return -1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] < nums[i-1])
                return (i-1);
        }
        
        return nums.size()-1;
    }
};

#endif /* _62_find_peek_element_h */
