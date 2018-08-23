//
//  681_next_closest_time.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _81_next_closest_time_h
#define _81_next_closest_time_h

class Solution {
public:
    string nextClosestTime(string time) {
        string res = "0000";
        vector<int> v{600, 60, 10, 1};
        int found = time.find(":");
        int cur = stoi(time.substr(0, found)) * 60 + stoi(time.substr(found + 1));
        for (int i = 1, d = 0; i <= 1440; ++i) {
            int next = (cur + i) % 1440;
            for (d = 0; d < 4; ++d) {
                res[d] = '0' + next / v[d];
                next %= v[d];
                if (time.find(res[d]) == string::npos) break;
            }
            if (d >= 4) break;
        }
        return res.substr(0, 2) + ":" + res.substr(2);
    }
};

#endif /* _81_next_closest_time_h */
