//
//  66_plus_one.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _6_plus_one_h
#define _6_plus_one_h

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int add = 0;
        add = (digits[len-1] + 1) / 10;
        digits[len-1] = (digits[len-1] + 1) % 10;
        int i = len - 2;
        while(add == 1 && i>=0){
            digits[i] = (digits[i] + add) % 10;
            add = (digits[i]==0) ? 1 : 0;
            --i;
        }
        
        if(add == 1) digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

#endif /* _6_plus_one_h */
