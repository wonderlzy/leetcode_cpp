//
//  264_nth_ugly_number.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _64_nth_ugly_number_h
#define _64_nth_ugly_number_h

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while(res.size() < n){
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int mn = min(m2, min(m3, m5));
            if(mn == m2) ++i2;
            if(mn == m3) ++i3;
            if(mn == m5) ++i5;
            res.push_back(mn);
        }
        
        return res.back();
    }
};

#endif /* _64_nth_ugly_number_h */
