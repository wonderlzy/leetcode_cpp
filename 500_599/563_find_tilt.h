//
//  563_find_tilt.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _63_find_tilt_h
#define _63_find_tilt_h

#include "../base_structure.h"
class Solution {
public:
    int findTilt(TreeNode* root) {
        int res = 0;
        postorder(root, res);
        return res;
    }
    int postorder(TreeNode* node, int& res) {
        if (!node) return 0;
        int leftSum = postorder(node->left, res);
        int rightSum = postorder(node->right, res);
        res += abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }
};

#endif /* _63_find_tilt_h */
