//
//  636_exclusive_time.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _36_exclusive_time_h
#define _36_exclusive_time_h

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int preTime = 0;
        for (string log : logs) {
            int found1 = log.find(":");
            int found2 = log.find_last_of(":");
            int idx = stoi(log.substr(0, found1));
            string type = log.substr(found1 + 1, found2 - found1 - 1);
            int time = stoi(log.substr(found2 + 1));
            if (!st.empty()) {
                res[st.top()] += time - preTime;
            }
            preTime = time;
            if (type == "start") st.push(idx);
            else {
                auto t = st.top(); st.pop();
                ++res[t];
                ++preTime;
            }
        }
        return res;
    }
};

#endif /* _36_exclusive_time_h */
