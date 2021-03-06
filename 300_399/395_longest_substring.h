//
//  395_longest_substring.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _95_longest_substring_h
#define _95_longest_substring_h

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, i = 0, n = s.size();
        while(i+k <= n){
            int m[26] = {0}, mask = 0, max_idx = i;
            
            for(int j = i; j < n; ++j){
                int t = s[j] - 'a';
                ++m[t];
                if(m[t] < k) mask |= (1 << t);
                else mask &= (~(1 << t));
                
                if(mask == 0){
                    res = max(res, j-i+1);
                    max_idx = j;
                }
            }
            
            i = max_idx + 1;
        }
        
        return res;
    }
};

#endif /* _95_longest_substring_h */
