//
//  290_word_pattern.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _90_word_pattern_h
#define _90_word_pattern_h

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        istringstream in(str);
        int i = 0;
        for(string word; in >> word; ++i){
            if(m.find(pattern[i]) != m.end()){
                if(m[pattern[i]] != word) return false;
            } else {
                for(unordered_map<char, string>::iterator iter = m.begin(); iter != m.end(); ++iter){
                    if(iter->second == word) return false;
                }
                
                m[pattern[i]] = word;
            }
        }
        return i == pattern.size();
    }
};

#endif /* _90_word_pattern_h */
