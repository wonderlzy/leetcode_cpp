//
//  600_find_integers.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _00_find_integers_h
#define _00_find_integers_h

class Solution {
public:
    int findIntegers(int num) {
        int res = 0, k = 31, pre = 0;
        vector<int> f(32, 0);
        f[0] = 1; f[1] = 2;
        
        for(int i=2; i<31; ++i)
            f[i] = f[i-1] + f[i-2];
        
        while(k>=0){
            if(num & (1<<k)){
                res += f[k];
                if(pre) return res;
                pre = 1;
            } else
                pre = 0;
            --k;
        }
        
        return res + 1;
    }
};

#endif /* _00_find_integers_h */
