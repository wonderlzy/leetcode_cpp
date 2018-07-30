//
//  139_word_break.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _39_word_break_h
#define _39_word_break_h

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const size_t n = s.size();
        vector<bool> res(n+1, false);
        res[0] = true;
        
        for(int i=0; i<n+1; ++i){
            for(int j=0; j<i; ++j){
                if(res[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()){
                    res[i] = true;
                    break;
                }
            }
        }
        
        return res[n];
    }
};

#endif /* _39_word_break_h */
