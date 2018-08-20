//
//  465_min_transfers.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _65_min_transfers_h
#define _65_min_transfers_h

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for (auto t : transactions) {
            m[t[0]] -= t[2];
            m[t[1]] += t[2];
        }
        vector<int> accnt(m.size());
        int cnt = 0;
        for (auto a : m) {
            if (a.second != 0) accnt[cnt++] = a.second;
        }
        return helper(accnt, 0, cnt, 0);
    }
    int helper(vector<int>& accnt, int start, int n, int num) {
        int res = INT_MAX;
        while (start < n && accnt[start] == 0) ++start;
        for (int i = start + 1; i < n; ++i) {
            if ((accnt[i] < 0 && accnt[start] > 0) || (accnt[i] > 0 && accnt[start] < 0)) {
                accnt[i] += accnt[start];
                res = min(res, helper(accnt, start + 1, n, num + 1));
                accnt[i] -= accnt[start];
            }
        }
        return res == INT_MAX ? num : res;
    }
};

#endif /* _65_min_transfers_h */
