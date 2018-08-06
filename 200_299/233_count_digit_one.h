//
//  233_count_digit_one.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _33_count_digit_one_h
#define _33_count_digit_one_h

class Solution {
public:
    int countDigitOne(int n) {
        if(n < 1) return 0;
        int len = getLen(n);
        if(len == 1) return 1;
        
        int tmp1 = pow(10, len-1);
        int first = n / tmp1;
        int firstOneNum = first==1 ? n%tmp1 + 1 : tmp1;
        int otherOneNum = first * (len-1) * (tmp1 / 10);
        
        return firstOneNum + otherOneNum + countDigitOne(n%tmp1);
    }
    
    int getLen(int num){
        int res = 0;
        while(num != 0){
            ++res;
            num /= 10;
        }
        return res;
    }
};

#endif /* _33_count_digit_one_h */
