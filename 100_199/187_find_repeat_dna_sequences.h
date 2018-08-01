//
//  185_find_repeat_dna_sequences.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _85_find_repeat_dna_sequences_h
#define _85_find_repeat_dna_sequences_h

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.empty()) return {};
        
        unordered_set<string> res;
        unordered_set<int> st;
        int cur = 0, i = 0;
        
        while(i<9)
            cur = cur << 3 | (s[i++] & 7);
        
        while(i < s.size()){
            cur = ((cur & 0x7ffffff) << 3) | (s[i++] & 7);
            if(st.count(cur))
               res.insert(s.substr(i-10, 10));
            else
                st.insert(cur);
        }
        
        return vector<string>(res.begin(), res.end());
    }
};

#endif /* _85_find_repeat_dna_sequences_h */
