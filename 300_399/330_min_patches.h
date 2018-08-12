//
//  330_min_patches.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _30_min_patches_h
#define _30_min_patches_h

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, res = 0, i = 0;
        
        while(miss <= n){
            if(i < nums.size() && nums[i] <= miss)
                miss += nums[i++];
            else{
                miss += miss;
                ++res;
            }
        }
        
        return res;
    }
};

#endif /* _30_min_patches_h */
