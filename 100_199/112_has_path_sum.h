//
//  112_has_path_sum.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/19.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _12_has_path_sum_h
#define _12_has_path_sum_h

#include "base_structure.h"
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right && root->val==sum)
            return true;
        
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

#endif /* _12_has_path_sum_h */
