//
//  65_is_number.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _5_is_number_h
#define _5_is_number_h

class Solution {
public:
    bool isNumber(string s) {
        return isNumber(s.c_str());
    }
    
private:
    bool isNumber(char const* ch){
        char* endptr;
        strtod(ch, &endptr);
        
        if(endptr == ch) return false;
        for(; *endptr; ++endptr)
            if(!isspace(*endptr)) return false;
        
        return true;
    }
};

#endif /* _5_is_number_h */
