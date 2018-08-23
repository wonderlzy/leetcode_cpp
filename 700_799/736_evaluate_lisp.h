//
//  736_evaluate_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018年 zhongyingli. All rights reserved.
//

#ifndef _36_evaluate_lisp_h
#define _36_evaluate_lisp_h

class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, int> m;
        return helper(expression, m);
    }
    int helper(string str, unordered_map<string, int> m) {
        if (str[0] == '-' || (str[0] >= '0' && str[0] <= '9')) return stoi(str);
        else if (str[0] != '(') return m[str];
        string s = str.substr(1, str.size() - 2);
        int cur = 0;
        string cmd = parse(s, cur);
        if (cmd == "let") {
            while (true) {
                string var = parse(s, cur);
                if (cur > s.size()) return helper(var, m);
                string t = parse(s, cur);
                m[var] = helper(t, m);
            }
        } else if (cmd == "add") {
            return helper(parse(s, cur), m) + helper(parse(s, cur), m);
        } else if (cmd == "mult") {
            return helper(parse(s, cur), m) * helper(parse(s, cur), m);
        }
    }
    string parse(string& s, int& cur) {
        int end = cur + 1, t = cur, cnt = 1;
        if (s[cur] == '(') {
            while (cnt != 0) {
                if (s[end] == '(') ++cnt;
                else if (s[end] == ')') --cnt;
                ++end;
            }
        } else {
            while (end < s.size() && s[end] != ' ') ++end;
        }
        cur = end + 1;
        return s.substr(t, end - t);
    }
};

#endif /* _36_evaluate_list_h */
