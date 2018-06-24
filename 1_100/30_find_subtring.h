//
//  30_find_subtring.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/22.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _0_find_subtring_h
#define _0_find_subtring_h

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty() || words.empty()) return result;
        
        unsigned long word_len = words.front().length();
        unsigned long cat_len = words.size()*word_len;
        if(s.length() < cat_len)  return result;
        
        unordered_map<string, int> key_value, unused;
        for(auto word : words)
                ++key_value[word];
        
        for(auto i=begin(s); i<=prev(end(s), cat_len); ++i){
            //unordered_map<string, int> unused(key_value);
            unused = key_value;
            
            for(auto j=i; j!=next(i,cat_len); j+=word_len){
                auto pos = unused.find(string(j,next(j, word_len)));
                if(pos == unused.end() || pos->second==0)
                    break;
                if(--pos->second == 0) unused.erase(pos);
            }
            
            if(unused.size() == 0) result.push_back(distance(begin(s), i));
        }
        
        return result;
    }
};

#endif /* _0_find_subtring_h */
