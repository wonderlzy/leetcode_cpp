//
//  623_add_one_row.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _23_add_one_row_h
#define _23_add_one_row_h

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 0 || d == 1) {
            TreeNode *newRoot = new TreeNode(v);
            (d ? newRoot->left : newRoot->right) = root;
            return newRoot;
        }
        if (root && d > 1) {
            root->left = addOneRow(root->left, v, d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right, v, d > 2 ? d - 1 : 0);
        }
        return root;
    }
};

#endif /* _23_add_one_row_h */
