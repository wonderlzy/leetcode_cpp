//
//  503_find_maximum_capital.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _03_find_maximum_capital_h
#define _03_find_maximum_capital_h

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int, int>> v;
        for (int i = 0; i < Capital.size(); ++i) {
            v.push_back({Capital[i], Profits[i]});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < k; ++i) {
            int left = 0, right = v.size(), mx = 0, idx = 0;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (v[mid].first <= W) left = mid + 1;
                else right = mid;
            }
            for (int j = right - 1; j >= 0; --j) {
                if (mx < v[j].second) {
                    mx = v[j].second;
                    idx = j;
                }
            }
            W += mx;
            v.erase(v.begin() + idx);
        }
        return W;
    }
};

#endif /* _03_find_maximum_capital_h */
