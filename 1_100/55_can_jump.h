//
//  55_can_jump.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _5_can_jump_h
#define _5_can_jump_h

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        int last = 0;
        int cur = 0;
        for(int i=0; i<nums.size(); ++i){
            if(i>last){
                if(i>cur) return false;
                else last = cur;
            }
            
            cur = max(cur, i+nums[i]);
        }
        
        return cur<nums.size()-1 ? false : true;
    }
};

#endif /* _5_can_jump_h */
