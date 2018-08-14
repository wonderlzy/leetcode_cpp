//
//  404_sum_left_leaves.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _04_sum_left_leaves_h
#define _04_sum_left_leaves_h

#include "../base_structure.h"
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root->left && !root->left->left && !root->left->right)
            return root->left->val+sumOfLeftLeaves(root->right);
        else
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

#endif /* _04_sum_left_leaves_h */
