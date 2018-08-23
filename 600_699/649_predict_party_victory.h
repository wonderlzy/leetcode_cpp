//
//  649_predict_party_victory.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _49_predict_party_victory_h
#define _49_predict_party_victory_h

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> q1, q2;
        for (int i = 0; i < n; ++i) {
            (senate[i] == 'R') ? q1.push(i) : q2.push(i);
        }
        while (!q1.empty() && !q2.empty()) {
            int i = q1.front(); q1.pop();
            int j = q2.front(); q2.pop();
            (i < j) ? q1.push(i + n) : q2.push(j + n);
        }
        return (q1.size() > q2.size()) ? "Radiant" : "Dire";
    }
};

#endif /* _49_predict_party_victory_h */
