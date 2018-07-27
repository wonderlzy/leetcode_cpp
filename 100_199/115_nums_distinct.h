//
//  115_nums_distinct.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/19.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _15_nums_distinct_h
#define _15_nums_distinct_h

#include "base_structure.h"
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        vector<int> dp(t.size()+1, 0);
        dp[0] = 1;
        
        for(int i=1; i<=s.size(); ++i){
            for(int j=t.size(); j>=1; --j){
                dp[j] = dp[j] + ((s[i-1]==t[j-1]) ? dp[j-1] : 0 );
            }
        }
        
        return dp[t.size()];
        
        
        /*
        int dp[s.size()+1][t.size()+1];
        
        dp[0][0] = 1;
        for(int j=1; j<=t.size(); ++j)
            dp[0][j] = 0;
        for(int i=1; i<=s.size(); ++i)
            dp[i][0] = 1;
        
        for(int i=1; i<=s.size(); ++i){
            for(int j=1; j<=t.size(); ++j){
                dp[i][j] = dp[i-1][j] + ((s[i-1]==t[j-1]) ? dp[i-1][j-1] : 0 );
            }
        }
        
        return dp[s.size()][t.size()];
        */
        
        /*
        int dp[t.size()+1][s.size()+1];
        
        for(int j=0; j<=s.size(); ++j)
            dp[0][j] = 1;
        for(int i=1; i<=t.size(); ++i)
            dp[i][0] = 0;
        
        for(int i=1; i<=t.size(); ++i){
            for(int j=1; j<=s.size(); ++j){
                dp[i][j] = dp[i][j-1] + ((t[i-1] == s[j-1]) ? dp[i-1][j-1] : 0);
            }
        }
        
        return dp[t.size()][s.size()];
        */
        
        /*
        vector<int> dp(t.size() + 1);
        dp[0] = 1;
        
        for(int i=0; i<s.size(); ++i){
            for(int j=t.size()-1; j>=0; --j){
                dp[j+1] += s[i]==t[j] ? dp[j] : 0;
            }
        }
     
        return dp[t.size()];
        */
    }
};

#endif /* _15_nums_distinct_h */
