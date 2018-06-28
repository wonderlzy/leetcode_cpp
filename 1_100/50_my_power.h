//
//  50_my_power.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/28.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _0_my_power_h
#define _0_my_power_h

class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
            return quickPow(1/x, -n);
        else
            return quickPow(x, n);
    }
    
    double quickPow(double x, int n){
        if(n == 0) return 1;
        double half = quickPow(x, n/2);
        
        return n%2 ? half * half * x : half * half;
    }
};

#endif /* _0_my_power_h */
