//
//  140_word_break2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _40_word_break2_h
#define _40_word_break2_h

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> m;
        return recursive(s, wordDict, m);
    }
    
private:
    vector<string> recursive(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& m){
        if(m.count(s)) return m[s];
        if(s.empty()) return {""};
        
        vector<string> res;
        for(auto word : wordDict){
            if(s.substr(0, word.size()) != word)
                continue;
            
            vector<string> rem = recursive(s.substr(word.size()), wordDict, m);
            for(string str : rem){
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        
        return m[s] = res;
    }
};

#endif /* _40_word_break2_h */
