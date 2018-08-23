//
//  654_construct_maximun_binary_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _54_construct_maximun_binary_tree_h
#define _54_construct_maximun_binary_tree_h

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return NULL;
        int mx = INT_MIN, mx_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (mx < nums[i]) {
                mx = nums[i];
                mx_idx = i;
            }
        }
        TreeNode *node = new TreeNode(mx);
        vector<int> leftArr = vector<int>(nums.begin(), nums.begin() + mx_idx);
        vector<int> rightArr = vector<int>(nums.begin() + mx_idx + 1, nums.end());
        node->left = constructMaximumBinaryTree(leftArr);
        node->right = constructMaximumBinaryTree(rightArr);
        return node;
    }
};

#endif /* _54_construct_maximun_binary_tree_h */
