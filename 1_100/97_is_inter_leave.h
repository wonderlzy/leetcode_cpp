//
//  97_is_inter_leave.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/10.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _7_is_inter_leave_h
#define _7_is_inter_leave_h

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        
        if (s1.length() < s2.length())
            return isInterleave(s2, s1, s3);
        
        vector<bool> f(s2.length() + 1, true);
        for (size_t i = 1; i <= s2.length(); ++i)
            f[i] = s2[i - 1] == s3[i - 1] && f[i - 1];
        
        for (size_t i = 1; i <= s1.length(); ++i) {
            f[0] = s1[i - 1] == s3[i - 1] && f[0];
            for (size_t j = 1; j <= s2.length(); ++j)
                f[j] = (s1[i - 1] == s3[i + j - 1] && f[j])
                || (s2[j - 1] == s3[i + j - 1] && f[j - 1]);
        }
        return f[s2.length()];
        
        /*
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> fill(s1.size()+1, vector<bool>(s2.size()+1, true));
        
        for(int i=1; i<=s1.size(); ++i)
            fill[i][0] = fill[i-1][0] && (s1[i-1]==s3[i-1]);
        
        for(int j=1; j<=s2.size(); ++j)
            fill[0][j] = fill[0][j-1] && (s2[j-1]==s3[j-1]);
        
        for(int i=1; i<=s1.size(); ++i){
            for(int j=1; j<=s2.size(); ++j){
                fill[i][j] = (fill[i-1][j] && s1[i-1]==s3[i+j-1]) || (fill[i][j-1] && (s2[j-1]==s3[i+j-1]));
            }
        }
        
        return fill[s1.size()][s2.size()];
        */
    }
};

#endif /* _7_is_inter_leave_h */
