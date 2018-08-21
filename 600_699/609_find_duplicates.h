//
//  609_find_duplicates.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _09_find_duplicates_h
#define _09_find_duplicates_h

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string path : paths) {
            istringstream is(path);
            string pre = "", t = "";
            is >> pre;
            while (is >> t) {
                int idx = t.find_last_of('(');
                string dir = pre + "/" + t.substr(0, idx);
                string content = t.substr(idx + 1, t.size() - idx - 2);
                m[content].push_back(dir);
            }
        }
        for (auto a : m) {
            if (a.second.size() > 1)res.push_back(a.second);
        }
        return res;
    }
};

#endif /* _09_find_duplicates_h */
