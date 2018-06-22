//
//  8_atoi.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/12.
//  Copyright © 2018年 zhongyingli. All rights reserved.
//

#ifndef __atoi_h
#define __atoi_h

class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        long long max_int = ~(1<<31);
        if(str.length()==0 )
            return 0;

        //处理第一个字符
        bool sign = false;
        int i =0;
        while(str[i]==' ' && i<str.length()) i++;
        
        if(str[i] == '+'){
            sign = false;
            i++;
        }
        else if(str[i] == '-'){
            sign = true;
            i++;
        }
        
        for(; i<str.length(); i++){
            if(str[i]<'0' || str[i]>'9')
                break;
            result = result * 10 + str[i]-'0';
            
            //整数溢出
            if(result>max_int)
                return sign ? -(max_int+1) : max_int;
        }
        
        return sign ? -result : result;
    }
};

#endif /* __atoi_h */
