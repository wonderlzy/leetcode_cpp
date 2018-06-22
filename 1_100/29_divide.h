//
//  29_divide.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _9_divide_h
#define _9_divide_h

class Solution {
public:
    int divide(int dividend, int divisor) {
        /*long dend = dividend, sor = divisor;
        long quotient = 0;
        bool positive = (dend>0 && sor>0) || (dend<0 && sor<0);
        dend = dend < 0 ? -dend : dend;
        sor = sor < 0 ? -sor : sor;
        
        while(dend>=sor){
            if(++quotient > INT_MAX) return INT_MAX;
            dend -= sor;
        }
        
        if(quotient > INT_MAX) return INT_MAX;
        
        return positive ? quotient : -quotient;
         */
        long long a = dividend > 0 ? dividend : -(long long)dividend;
        long long b = divisor > 0 ? divisor : -(long long) divisor;
        
        long long result = 0;
        while(a >= b){
            long long c = b;
            for(int i=0; a >= c; ++i, c <<= 1){
                a -= c;
                result += 1 << i;
            }
        }
        
        return ((dividend^divisor) >> 31) ? (-result) : (result);
    }
};

#endif /* _9_divide_h */
