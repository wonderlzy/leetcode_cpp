//
//  32_longest_valid_parenthesis.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _2_longest_valid_parenthesis_h
#define _2_longest_valid_parenthesis_h

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0, start = -1;
        stack<int> ch_stack;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '(')
                ch_stack.push(i);
            else{
                if(ch_stack.empty())
                    start = i;
                else{
                    ch_stack.pop();
                    if(ch_stack.empty())
                        max_len = max(max_len, i-start);
                    else
                        max_len = max(max_len, i-ch_stack.top());
                }
            }
        }
        
        return max_len;
        /*int ret = 0;
        if(s.size() < 2) return ret;
        vector<int> fill(s.size(), 0);
        
        for(int i=s.size()-2; i>=0; --i){
            int match = i+fill[i+1]+1;
            if(s[i] == '(' && s[match]==')' && match<s.size()){
                fill[i] = fill[i+1] + 2;
                
                if(match+1<s.size())
                    fill[i] += fill[match+1];
            }
            
            ret = max(ret, fill[i]);
        }
        
        return ret;
        */
    }
};

#endif /* _2_longest_valid_parenthesis_h */
