//
//  709_to_lower_case.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _09_to_lower_case_h
#define _09_to_lower_case_h

class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0; i < str.length(); i++) {
            str[i] = str[i] >= 'A' && str[i] <= 'Z' ? str[i] + 32: str[i];
        }
        
        return str;
        
        /*
        for (int i=0; i<str.length(); i++)
        {
            if (isupper(str[i]))
                str[i]=tolower(str[i]);
        }
        return str;
         */
    }
};

#endif /* _09_to_lower_case_h */
