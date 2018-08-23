//
//  671_find_second_minimum_value.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _71_find_second_minimum_value_h
#define _71_find_second_minimum_value_h

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int first = root->val, second = INT_MAX;
        helper(root, first, second);
        return (second == first || second == INT_MAX) ? -1 : second;
    }
    void helper(TreeNode* node, int& first, int& second) {
        if (!node) return;
        if (node->val != first && node->val < second) {
            second = node->val;
        }
        helper(node->left, first, second);
        helper(node->right, first, second);
    }
};

#endif /* _71_find_second_minimum_value_h */
