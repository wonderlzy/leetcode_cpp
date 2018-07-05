//
//  70_climb_stairs.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/4.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _0_climb_stairs_h
#define _0_climb_stairs_h

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int cur = 2, pre = 1;
        int result = 0;
        for(int i=3; i<n; ++i){
            result = cur + pre;
            pre = cur;
            cur = result;
        }
        
        return cur + pre;
    }
};

#endif /* _0_climb_stairs_h */
