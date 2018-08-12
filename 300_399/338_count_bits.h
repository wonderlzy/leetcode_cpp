//
//  338_count_bits.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _38_count_bits_h
#define _38_count_bits_h

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i=1; i<=num; ++i)
            res[i] = res[i&(i-1)] + 1;
        
        return res;
    }
};

#endif /* _38_count_bits_h */
