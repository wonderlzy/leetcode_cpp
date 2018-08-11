//
//  301_remove_invalid_parenthesis.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/9.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _01_remove_invalid_parenthesis_h
#define _01_remove_invalid_parenthesis_h

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(s, 0, 0, {'(',')'}, res);
        return res;
    }
    
private:
    void helper(string s, int last_i, int last_j, vector<char> p, vector<string>& res){
        int cnt = 0;
        for(int i=last_i; i<s.size(); ++i){
            if(s[i]==p[0]) ++cnt;
            else if (s[i]==p[1]) --cnt;
            if(cnt >= 0 ) continue;
            
            for(int j=last_j; j<=i; ++j){
                if(s[j]==p[1] && (j==last_j || s[j]!=s[j-1])){
                    helper(s.substr(0, j) + s.substr(j+1), last_i, j, p, res);
                }
            }
            
            return ;
        }
        
        string rev = string(s.rbegin(), s.rend());
        if(p[0] == '(') helper(rev, 0, 0, {')','('}, res);
        else res.push_back(rev);
    }
};

#endif /* _01_remove_invalid_parenthesis_h */
