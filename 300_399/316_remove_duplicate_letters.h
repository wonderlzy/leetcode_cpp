//
//  316_remove_duplicate_letters.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _16_remove_duplicate_letters_h
#define _16_remove_duplicate_letters_h

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[256] = {0}, visited[256] = {0};
        string res = "0";
        for(auto a : s)
            ++m[a];
        
        for(auto a : s){
            --m[a];
            if(visited[a]) continue;
            while(a < res.back() && m[res.back()]){
                visited[res.back()] = 0;
                res.pop_back();
            }
            
            res += a;
            visited[a] = 1;
        }
        
        return res.substr(1);
    }
};

#endif /* _16_remove_duplicate_letters_h */
