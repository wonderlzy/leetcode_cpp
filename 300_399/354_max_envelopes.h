//
//  354_max_envelopes.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _54_max_envelopes_h
#define _54_max_envelopes_h

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int res = 0, n = envelopes.size();
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
};

#endif /* _54_max_envelopes_h */
