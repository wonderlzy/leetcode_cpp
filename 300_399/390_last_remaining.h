//
//  390_last_remaining.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _90_last_remaining_h
#define _90_last_remaining_h

class Solution {
public:
    int lastRemaining(int n) {
        return n==1 ? 1 : 2*(1 + n/2 - lastRemaining(n/2));
    }
};

#endif /* _90_last_remaining_h */
