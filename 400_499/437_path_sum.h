//
//  437_path_sum.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _37_path_sum_h
#define _37_path_sum_h

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int sumUp(TreeNode* node, int pre, int& sum) {
        if (!node) return 0;
        int cur = pre + node->val;
        return (cur == sum) + sumUp(node->left, cur, sum) + sumUp(node->right, cur, sum);
    }
};

#endif /* _37_path_sum_h */
