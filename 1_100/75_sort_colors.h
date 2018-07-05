//
//  75_sort_colors.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/4.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _5_sort_colors_h
#define _5_sort_colors_h

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() <= 1) return ;
        
        int red = 0, blue = nums.size() - 1;
        for(int i=0; i<blue+1;){
            if(nums[i] == 0)
                swap(nums[i++], nums[red++]);
            else if(nums[i] == 2)
                swap(nums[i], nums[blue--]);
            else
                ++i;
        }
        
        return ;
    }
};

#endif /* _5_sort_colors_h */
