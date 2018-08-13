//
//  399_cacul_equation.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _99_cacul_equation_h
#define _99_cacul_equation_h

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res(queries.size(), -1);
        set<string> s;
        for (auto a : equations) {
            s.insert(a.first);
            s.insert(a.second);
        }
        for (int i = 0; i < queries.size(); ++i) {
            vector<string> query{queries[i].first, queries[i].second};
            if (s.count(query[0]) && s.count(query[1])) {
                vector<int> v;
                res[i] = helper(equations, values, query, v);
            }
        }
        return res;
    }
    double helper(vector<pair<string, string>> equations, vector<double>& values, vector<string> query, vector<int>& v) {
        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i].first == query[0] && equations[i].second == query[1]) return values[i];
            if (equations[i].first == query[1] && equations[i].second == query[0]) return 1.0 / values[i];
        }
        for (int i = 0; i < equations.size(); ++i) {
            if (find(v.begin(), v.end(), i) == v.end() && equations[i].first == query[0]) {
                v.push_back(i);
                double t = values[i] * helper(equations, values, {equations[i].second, query[1]}, v);
                if (t > 0) return t;
                else v.pop_back();
            }
            if (find(v.begin(), v.end(), i) == v.end() && equations[i].second == query[0]) {
                v.push_back(i);
                double t = helper(equations, values, {equations[i].first, query[1]}, v) / values[i];
                if (t > 0) return t;
                else v.pop_back();
            }
        }
        return -1.0;
    }
};

#endif /* _99_cacul_equation_h */
