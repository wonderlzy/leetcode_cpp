//
//  38_count_and_say.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/26.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _8_count_and_say_h
#define _8_count_and_say_h

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string say = countAndSay(n-1);
        string result;
        int i= 0, count = 0;
        while(i<say.size()){
            char ch = say[i];
            count = 0;
            while(say[i] == ch && i<say.size()){
                ++count;
                ++i;
            }
            result.push_back(count+'0');
            result.push_back(ch);
        }
        
        return result;
    }
};

#endif /* _8_count_and_say_h */
