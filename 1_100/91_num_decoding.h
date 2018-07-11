//
//  91_num_decoding.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/9.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _1_num_decoding_h
#define _1_num_decoding_h

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
            
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i=1; i<dp.size(); ++i){
            dp[i] = s[i-1]=='0' ? 0 : dp[i-1];
            
            if(i>1 && (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6')))
                dp[i] += dp[i-2];
        }
       
        return dp.back();
    }
};

#endif /* _1_num_decoding_h */
