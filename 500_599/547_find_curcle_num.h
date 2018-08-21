//
//  547_find_curcle_num.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _47_find_curcle_num_h
#define _47_find_curcle_num_h


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = n;
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    int p1 = getRoot(root, i);
                    int p2 = getRoot(root, j);
                    if (p1 != p2) {
                        --res;
                        root[p2] = p1;
                    }
                }
            }
        }
        return res;
    }
    int getRoot(vector<int>& root, int i) {
        while (i != root[i]) {
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }
};

#endif /* _47_find_curcle_num_h */
