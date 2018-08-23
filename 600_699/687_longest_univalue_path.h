//
//  687_longest_univalue_path.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _87_longest_univalue_path_h
#define _87_longest_univalue_path_h

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        helper(root, root, res);
        return res;
    }
    int helper(TreeNode* node, TreeNode* parent, int& res) {
        if (!node) return 0;
        int left = helper(node->left, node, res);
        int right = helper(node->right, node, res);
        left = (node->left && node->val == node->left->val) ? left + 1 : 0;
        right = (node->right && node->val == node->right->val) ? right + 1 : 0;
        res = max(res, left + right);
        return max(left, right);
    }
};

#endif /* _87_longest_univalue_path_h */
