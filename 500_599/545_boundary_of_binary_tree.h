//
//  545_boundary_of_binary_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _45_boundary_of_binary_tree_h
#define _45_boundary_of_binary_tree_h

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res{root->val};
        helper(root->left, true, false, res);
        helper(root->right, false, true, res);
        return res;
    }
    void helper(TreeNode* node, bool leftbd, bool rightbd, vector<int>& res) {
        if (!node) return;
        if (!node->left && !node->right) {
            res.push_back(node->val);
            return;
        }
        if (leftbd) res.push_back(node->val);
        helper(node->left, leftbd && node->left, rightbd && !node->right, res);
        helper(node->right, leftbd && !node->left, rightbd && node->right, res);
        if (rightbd) res.push_back(node->val);
    }
};

#endif /* _45_boundary_of_binary_tree_h */
