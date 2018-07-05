//
//  72_min_distance.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/4.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _2_min_distance_h
#define _2_min_distance_h

class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
        const size_t m = word1.length() + 1;
        const size_t n = word2.length() + 1;
        
        int dp[m][n];
        for(size_t i = 0; i < m; ++i)
            dp[i][0] = i;
        for(size_t j = 0; j < n; ++j)
            dp[0][j] = j;
        
        for(size_t i = 1; i < m; ++i){
            for(size_t j = 1; j < n; ++j){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    int ms = min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = 1 + min(ms, dp[i-1][j-1]);
                }
            }
        }
        
        return dp[m-1][n-1];
        */
        if(word1.size() < word2.size()) return minDistance(word2, word1);
        
        const size_t m = word1.size();
        const size_t n = word2.size();
        int left_up = 0;
        int dp[n+1];
        
        for(size_t i = 0; i <= n; ++i)
            dp[i] = i;
        
        for(size_t i=1; i<=m; ++i){
            left_up = dp[0];
            dp[0] = i;
            
            for(size_t j=1; j<=n; ++j){
                int up = dp[j];
                if(word1[i-1] == word2[j-1])
                    dp[j] = left_up;
                else{
                    int ms = min(dp[j-1], dp[j]);
                    dp[j] = 1 + min(ms, left_up);
                }
                
                left_up = up;
            }
        }
        
        return dp[n];
    }
};

#endif /* _2_min_distance_h */
