//
//  343_integer_break.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _43_integer_break_h
#define _43_integer_break_h

class Solution {
public:
    int integerBreak(int n) {
        int res = 1;
        if(n <= 1) return 0;
        if(n == 2 || n == 3) return n-1;
        while(n > 4){
            n -= 3;
            res *= 3;
        }
        return res*n;
    }
};

/*
 直接利用导数的基本性质就可以证明了。
 假设n可以拆分成k个实数（而非正整数）的和：n=km，那么相应的乘积是pow(m, k) = pow(n/k, k), 要maximize这个值，take log, f = k(ln(n)-ln(k)), then take derivative, f' = ln(n) - ln(k) - 1 = 0。所以optimal 的k = n/e，相应的m=e=2.7...。所以如果m是正整数的话，尽可能的向3 round up，剩下的2来凑。
 */

#endif /* _43_integer_break_h */
