//
//  721_merge_acounts.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _21_merge_acounts_h
#define _21_merge_acounts_h

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n = accounts.size();
        unordered_map<string, vector<int>> m;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                m[accounts[i][j]].push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i] != 0) continue;
            queue<int> q{{i}};
            set<string> s;
            while (!q.empty()) {
                int t = q.front(); q.pop();
                visited[t] = 1;
                vector<string> mails(accounts[t].begin() + 1, accounts[t].end());
                for (string mail : mails) {
                    s.insert(mail);
                    for (int user : m[mail]) {
                        if (visited[user] != 0) continue;
                        q.push(user);
                        visited[user] = 1;
                    }
                }
            }
            vector<string> out(s.begin(), s.end());
            out.insert(out.begin(), accounts[i][0]);
            res.push_back(out);
        }
        return res;
    }
};

#endif /* _21_merge_acounts_h */
