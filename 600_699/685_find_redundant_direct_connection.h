//
//  685_find_redundant_direct_connection.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _85_find_redundant_direct_connection_h
#define _85_find_redundant_direct_connection_h

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> root(n + 1, 0), first, second;
        for (auto& edge : edges) {
            if (root[edge[1]] == 0) {
                root[edge[1]] = edge[0];
            } else {
                first = {root[edge[1]], edge[1]};
                second = edge;
                edge[1] = 0;
            }
        }
        for (int i = 0; i <= n; ++i) root[i] = i;
        for (auto& edge : edges) {
            if (edge[1] == 0) continue;
            int x = getRoot(root, edge[0]), y = getRoot(root, edge[1]);
            if (x == y) return first.empty() ? edge : first;
            root[x] = y;
        }
        return second;
    }
    int getRoot(vector<int>& root, int i) {
        return i == root[i] ? i : getRoot(root, root[i]);
    }
};

#endif /* _85_find_redundant_direct_connection_h */
