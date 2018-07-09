//
//  87_is_scramble.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/9.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _7_is_scramble_h
#define _7_is_scramble_h

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        vector<int> letter(26,0);
        const size_t n = s1.size();
        for (int i = 0; i < n; ++i)
        {
            ++letter[s1[i] - 'a'];
            --letter[s2[i] - 'a'];
        }
        for (int& i : letter)
        {
            if (i != 0)
                return false;
        }
        
        for (int i = 1; i <= n-1; ++i)
        {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0,i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i)))
                return true;
        }
        return false;
        /*
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        const size_t n = s1.size();
        
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1, false)));
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)
                dp[i][j][1] = (s1[i] == s2[j]) ? true : false;
        }
        
        for(int len = 2; len <= n; ++len){
            for(int i=0; i<=n-len; ++i){
                for(int j=0; j<=n-len; ++j){
                    for(int k=1; k<len; ++k){
                        if((dp[i][j][k] && dp[i+k][j+k][len-k]) || (dp[i][j+len-k][k] && dp[i+k][j][len-k]) )
                            dp[i][j][len] = true;
                    }
                }
            }
        }
        
        return dp[0][0][n];
        */
    }
};

#endif /* _7_is_scramble_h */
