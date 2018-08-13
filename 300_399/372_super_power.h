//
//  372_super_power.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _72_super_power_h
#define _72_super_power_h

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long long res = 1;
        for(auto vec : b){
            res = pow(res, 10) * pow(a, vec) % 1337;
        }
        return res;
    }
    
    int pow(int x, int n){
        if(n == 0) return 1;
        if(n == 1) return x % 1337;
        return pow(x%1337, n/2) * pow(x%1337, n-n/2) % 1337;
    }
};


#endif /* _72_super_power_h */
