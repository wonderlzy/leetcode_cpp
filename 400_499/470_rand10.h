//
//  470_rand10.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _70_rand10_h
#define _70_rand10_h

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        auto x = (rand7()-1)*7 + rand7();
        return x<=40 ? x%10 +1 : rand10();
    }
};

#endif /* _70_rand10_h */
