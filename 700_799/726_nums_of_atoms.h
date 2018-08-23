//
//  726_nums_of_atoms.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _26_nums_of_atoms_h
#define _26_nums_of_atoms_h

class Solution {
public:
    string countOfAtoms(string formula) {
        string res = "";
        int pos = 0;
        map<string, int> m = parse(formula, pos);
        for (auto a : m) {
            res += a.first + (a.second == 1 ? "" : to_string(a.second));
        }
        return res;
    }
    map<string, int> parse(string& str, int& pos) {
        map<string, int> res;
        while (pos < str.size()) {
            if (str[pos] == '(') {
                ++pos;
                for (auto a : parse(str, pos)) res[a.first] += a.second;
            } else if (str[pos] == ')') {
                int i = ++pos;
                while (pos < str.size() && isdigit(str[pos])) ++pos;
                int multiple = stoi(str.substr(i, pos - i));
                for (auto a : res) res[a.first] *= multiple;
                return res;
            } else {
                int i = pos++;
                while (pos < str.size() && islower(str[pos])) ++pos;
                string elem = str.substr(i, pos - i);
                i = pos;
                while (pos < str.size() && isdigit(str[pos])) ++pos;
                string cnt = str.substr(i, pos - i);
                res[elem] += cnt.empty() ? 1 : stoi(cnt);
            }
        }
        return res;
    }
};

#endif /* _26_nums_of_atoms_h */
