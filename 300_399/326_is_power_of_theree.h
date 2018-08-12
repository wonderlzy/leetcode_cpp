//
//  326_is_power_of_theree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _26_is_power_of_theree_h
#define _26_is_power_of_theree_h

class Solution {
public:
    bool isPowerOfThree(int n) {
         return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
    }
};

#endif /* _26_is_power_of_theree_h */
