//
//  508_find_frequent_tree_sum.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _08_find_frequent_tree_sum_h
#define _08_find_frequent_tree_sum_h

#include "../base_structure.h"
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        unordered_map<int, int> m;
        int cnt = 0;
        postorder(root, m, cnt);
        for (auto a : m) {
            if (a.second == cnt) res.push_back(a.first);
        }
        return res;
    }
    int postorder(TreeNode* node, unordered_map<int, int>& m, int& cnt) {
        if (!node) return 0;
        int left = postorder(node->left, m, cnt);
        int right = postorder(node->right, m, cnt);
        int sum = left + right + node->val;
        cnt = max(cnt, ++m[sum]);
        return sum;
    }
};

#endif /* _08_find_frequent_tree_sum_h */
