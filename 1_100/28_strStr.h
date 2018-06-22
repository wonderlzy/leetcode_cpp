//
//  28_strStr.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _8_strStr_h
#define _8_strStr_h

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int hay_len = haystack.length();
        int nee_len = needle.length();
        
        bool finded = true;
        
        for(int i=0; i<=(hay_len-nee_len); ++i){
            finded = true;
            for(int j=0; j<nee_len; ++j){
                if(haystack[i+j] != needle[j]){
                    finded = false;
                    continue;
                }
            }
            if(finded) return i;
        }
        
        return -1;
    }
};

#endif /* _8_strStr_h */
