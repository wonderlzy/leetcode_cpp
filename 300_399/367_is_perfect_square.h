//
//  367_is_perfect_square.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _67_is_perfect_square_h
#define _67_is_perfect_square_h

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while(num > 0){
            num -= i;
            i += 2;
        }
        
        return num == 0;
    }
};

#endif /* _67_is_perfect_square_h */
