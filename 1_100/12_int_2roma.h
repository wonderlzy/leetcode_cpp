//
//  12_int_2roma.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _2_int_2roma_h
#define _2_int_2roma_h

class Solution {
public:
    string intToRoman(int num) {
        const int radius[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result;
        
        for(int i=0; num>0; i++){
            int count = num/radius[i];
            num = num % radius[i];
            
            for(; count>0; --count){
                result += symbol[i];
            }
        }
        
        return result;
    }
};

#endif /* _2_int_2roma_h */
