//
//  231_is_power_of2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _31_is_power_of2_h
#define _31_is_power_of2_h

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        long maxData = pow(2, 31);
        
        return !(maxData%n);
        
        if (n <= 0) {
            return false;
        }
        
        /*
        int cnt = 0;
        while(n > 0){
            cnt += (n&1);
            n >>= 1;
        }
        
        return cnt==1;
        */
    }
};

#endif /* _31_is_power_of2_h */
