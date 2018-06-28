//
//  45_jump_game2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/27.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _5_jump_game2_h
#define _5_jump_game2_h

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty()) return -1;
        
        int result = 0;
        int last = 0;
        int cur = 0;
        
        for(int i=0; i<nums.size(); ++i){
            if(i>last){
                last = cur;
                ++result;
            }
            
            cur = max(cur, i+nums[i]);
        }
        
        return result;
    }
};

#endif /* _5_jump_game2_h */
