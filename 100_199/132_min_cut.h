//
//  132_min_cut.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _32_min_cut_h
#define _32_min_cut_h

class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        int f[n+1];
        bool p[n][n];
        fill_n(&p[0][0], n*n, false);
        
        for(int i=0; i<=n; ++i)
            f[i] = n - i -1;
        
        for(int i = n-1; i>=0; --i){
            for(int j=i; j<n; ++j){
                if(s[i] == s[j] && (j-i<2 || p[i+1][j-1])){
                    p[i][j] = true;
                    f[i] = min(f[i], f[j+1]+1);
                }
            }
        }
        
        return f[0];
    }
};

#endif /* _32_min_cut_h */
