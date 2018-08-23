//
//  655_print_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _55_print_tree_h
#define _55_print_tree_h

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root), w = pow(2, h) - 1;
        vector<vector<string>> res(h, vector<string>(w, ""));
        helper(root, 0, w - 1, 0, h, res);
        return res;
    }
    void helper(TreeNode* node, int i, int j, int curH, int height, vector<vector<string>>& res) {
        if (!node || curH == height) return;
        res[curH][(i + j) / 2] = to_string(node->val);
        helper(node->left, i, (i + j) / 2, curH + 1, height, res);
        helper(node->right, (i + j) / 2 + 1, j, curH + 1, height, res);
    }
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};

#endif /* _55_print_tree_h */
