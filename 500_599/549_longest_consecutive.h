//
//  549_longest_consecutive.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _49_longest_consecutive_h
#define _49_longest_consecutive_h

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = helper(root, 1) + helper(root, -1) + 1;
        return max(res, max(longestConsecutive(root->left), longestConsecutive(root->right)));
    }
    int helper(TreeNode* node, int diff) {
        if (!node) return 0;
        int left = 0, right = 0;
        if (node->left && node->val - node->left->val == diff) {
            left = 1 + helper(node->left, diff);
        }
        if (node->right && node->val - node->right->val == diff) {
            right = 1 + helper(node->right, diff);
        }
        return max(left, right);
    }
};

#endif /* _49_longest_consecutive_h */
