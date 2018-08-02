//
//  204_count_primes.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _04_count_primes_h
#define _04_count_primes_h

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> num(n-1, true);
        num[0] = false;
        int res = 0, limit = sqrt(n);
        
        for(int i=2; i<=limit; ++i){
            if(num[i-1]){
                for(int j=i*i; j<n; j+=i){
                    num[j-1] = false;
                }
            }
        }
        
        for(int j=0; j<n-1; ++j){
            if(num[j]) ++res;
        }
        
        return res;
    }
};

#endif /* _04_count_primes_h */
