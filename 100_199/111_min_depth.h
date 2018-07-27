//
//  111_min_depth.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/19.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _11_min_depth_h
#define _11_min_depth_h

#include "base_structure.h"
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(!root->left)
            return minDepth(root->right) + 1;
        else if(!root->right)
            return minDepth(root->left) + 1;
        
        else return 1+min(minDepth(root->left), minDepth(root->right));
    }
};

#endif /* _11_min_depth_h */
