//
//  150_eval_rpn.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _50_eval_rpn_h
#define _50_eval_rpn_h

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        if(tokens.size() == 1) return atoi(tokens[0].c_str());
        stack<int> s;
        for(auto token : tokens ){
            if(token!= "+" && token!= "-" && token!="*" && token!="/"){
                s.push(atoi(token.c_str()));
            } else {
                int n = s.top();
                s.pop();
                int m = s.top();
                s.pop();
                
                if(token == "+")
                    s.push(m+n);
                if(token == "-")
                    s.push(m-n);
                if(token == "*")
                    s.push(m*n);
                if(token == "/")
                    s.push(m/n);
            }
        }
        
        return s.top();
    }
};

#endif /* _50_eval_rpn_h */
