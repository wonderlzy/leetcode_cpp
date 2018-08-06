//
//  242_is_anagram.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _42_is_anagram_h
#define _42_is_anagram_h

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> m(26, 0);
        for(int i=0; i<s.size(); ++i)
            ++m[s[i]-'a'];
        
        for(int j=0; j<t.size(); ++j){
            if(--m[t[j]-'a'] < 0)
                return false;
        }
        
        return true;
    }
};

#endif /* _42_is_anagram_h */
