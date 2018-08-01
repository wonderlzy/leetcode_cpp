//
//  189_rotate_array.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _89_rotate_array_h
#define _89_rotate_array_h

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty() || k % nums.size() == 0)
            return ;
        
        const size_t n = nums.size();
        const size_t cnt = k % n;
        reverse(nums.begin(), nums.begin()+n-cnt);
        reverse(nums.begin()+n-cnt, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

#endif /* _89_rotate_array_h */
