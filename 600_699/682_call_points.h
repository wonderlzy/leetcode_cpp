//
//  682_call_points.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _82_call_points_h
#define _82_call_points_h

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for (string op : ops) {
            if (op == "+") {
                v.push_back(v.back() + v[v.size() - 2]);
            } else if (op == "D") {
                v.push_back(2 * v.back());
            } else if (op == "C") {
                v.pop_back();
            } else {
                v.push_back(stoi(op));
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};

#endif /* _82_call_points_h */
