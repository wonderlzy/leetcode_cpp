//
//  13_roma_2int.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _3_roma_2int_h
#define _3_roma_2int_h

class Solution {
public:
    int romanToInt(string s) {
        const int radius[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        int result = 0;
        int i = 0, j = 0;
        
        for(; i<s.length() && j<=(sizeof(symbol)/sizeof(symbol[0])); j++){
            while(s.substr(i,1)==symbol[j]){
                result += radius[j];
                i++;
            }
            
            if(i<s.length() && s.substr(i,2)==symbol[j]){
                result += radius[j];
                i += 2;
            }
        }
        
        return result;
    }
};

#endif /* _3_roma_2int_h */
