//
//  20_is_valid.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/19.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _0_is_valid_h
#define _0_is_valid_h

class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        
        for(auto c : s){
            if(left.find(c) != string::npos)
                stk.push(c);
            else{
                if(stk.empty() || stk.top() != left[right.find(c)])
                    return false;
                else
                    stk.pop();
            }
        }
        
        return stk.empty();
    }
};

#endif /* _0_is_valid_h */
