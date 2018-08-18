//
//  424_character_replacement.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/17.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _24_character_replacement_h
#define _24_character_replacement_h

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, maxCnt = 0, start = 0;
        vector<int> counts(26, 0);
        
        for(int i=0; i<s.size(); ++i){
            maxCnt = max(maxCnt, ++counts[s[i]-'A']);
            while(i-start+1-maxCnt > k){
                --counts[s[start]-'A'];
                ++start;
            }
            
            res = max(res, i-start+1);
        }
        
        return res;
    }
};

#endif /* _24_character_replacement_h */
