//
//  376_wiggle_max_length.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _76_wiggle_max_length_h
#define _76_wiggle_max_length_h

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int p = 1, q = 1, n = nums.size();
        for(int i=1; i<n; ++i){
            if(nums[i] > nums[i-1])
                p = q + 1;
            else if(nums[i] < nums[i-1])
                q = p + 1;
        }
        
        return min(n, max(p, q));
        /*
        size_t n = nums.size();
        if(n < 2) return n;
        vector<int> up(n, 1);
        vector<int> down(n, 1);
        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(nums[i] > nums[j])
                    up[i] = max(up[i], down[j] + 1);
                else if(nums[i] < nums[j])
                    down[i] = max(down[i], up[j] + 1);
            }
        }
        
        return max(down.back(), up.back());
        */
    }
};

#endif /* _76_wiggle_max_length_h */
