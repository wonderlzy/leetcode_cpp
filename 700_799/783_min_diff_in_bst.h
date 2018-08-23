//
//  783_min_diff_in_bst.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _83_min_diff_in_bst_h
#define _83_min_diff_in_bst_h

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        vector<int> v;
        helper(root, v);
        for (int i = 1; i < v.size(); ++i) {
            res = min(res, v[i] - v[i - 1]);
        }
        return res;
    }
    void helper(TreeNode* node, vector<int>& vals) {
        if (!node) return;
        helper(node->left, vals);
        vals.push_back(node->val);
        helper(node->right, vals);
    }
};

#endif /* _83_min_diff_in_bst_h */
