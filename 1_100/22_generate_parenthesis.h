//
//  22_generate_parenthesis.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/19.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _2_generate_parenthesis_h
#define _2_generate_parenthesis_h

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path="";
        generate(n, n, 0, result, path);
        
        return result;
    }
    
    void generate(int n, int left, int right, vector<string>& result, string path){
        if(left == 0 && right == 0){
            result.push_back(path);
            return ;
        }
        
        if(left > 0)
            generate(n, left-1, right+1, result, path+"(");
        
        if(right > 0)
            generate(n, left, right-1, result, path+")");
        
    }
};

#endif /* _2_generate_parenthesis_h */
