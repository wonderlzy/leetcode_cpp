//
//  261_valid_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _61_valid_tree_h
#define _61_valid_tree_h

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, -1);
        for (auto a : edges) {
            int x = find(roots, a.first), y = find(roots, a.second);
            if (x == y) return false;
            roots[x] = y;
        }
        return edges.size() == n - 1;
    }
    int find(vector<int> &roots, int i) {
        while (roots[i] != -1) i = roots[i];
        return i;
    }
};

#endif /* _61_valid_tree_h */
