//
//  151_reverse_words.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _51_reverse_words_h
#define _51_reverse_words_h

class Solution {
public:
    void reverseWords(string &s) {
        int index = 0;
        const size_t n = s.size();
        reverse(s.begin(), s.end());
        
        for(int i=0; i<n; ++i){
            if(s[i] != ' '){
                if(index != 0)
                    s[index++] = ' ';
                int j = i;
                while(j<n && s[j]!=' ')
                    s[index++] = s[j++];
                
                reverse(s.begin()+index-(j-i), s.begin()+index);
                i = j;
            }
        }
        
        s.resize(index);
    }
};

#endif /* _51_reverse_words_h */
