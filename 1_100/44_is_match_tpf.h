//
//  44_is_match_tpf.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/27.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _4_is_match_tpf_h
#define _4_is_match_tpf_h

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        
        return isMatch(s.c_str(), p.c_str());
        
    }
    
    bool isMatch(const char *s, const char *p) {
        /*bool star = false;
        const char *str, *ptr;
        for (str = s, ptr = p; *str != '\0'; str++, ptr++) {
            switch (*ptr) {
                case '?':
                    break;
                case '*':
                    star = true;
                    s = str; p = ptr;
                    while (*p == '*') p++; //skip continuous '*'
                    if (*p == '\0') return true;
                    str = s - 1;
                    ptr = p - 1;
                    break;
                default:
                    if (*str != *ptr) {//
                        if (!star) return false;
                        s++;
                        str = s - 1;
                        ptr = p - 1;
                    }
                    break;
            }
        }
        
        while (*ptr == '*') ptr++;
        return (*ptr == '\0');
        */
        const int len1 = strlen(s);
        const int len2 = strlen(p);
        bool dp[len1+1][len2+1];
        
        if (*s == '\0') {
            while(*p == '*') p++;
            return *p == '\0';
        }
        if (*p == '\0') return false;
        
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        int len_s = strlen(s), len_p = strlen(p);
        for (int j = 1; j <= len_p; j++) {
            for (int i = 1; i <= len_s; i++) {
                if (dp[i-1][j-1] && (s[i-1] == p[j-1] || '?' == p[j-1])) dp[i][j] = true;
                if ('*' == p[j-1]) {
                    if (dp[i-1][j-1]) {
                        for (int k = i-1; k <= len_s; k++) dp[k][j] = true;
                        break;
                    } else if (dp[i][j-1]) {
                        for (int k = i; k <= len_s; k++) dp[k][j] = true;
                        break;
                    }
                }
            }
        }
        return dp[len_s][len_p];
    }
};

#endif /* _4_is_match_tpf_h */
