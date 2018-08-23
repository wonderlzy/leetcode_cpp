//
//  701_insert_into_bst.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _01_insert_into_bst_h
#define _01_insert_into_bst_h

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *cur = root, *node = new TreeNode(val);
        while (cur) {
            if (cur -> val > val) {
                if (cur -> left) {
                    cur = cur -> left;
                } else {
                    cur -> left = node;
                    break;
                }
            } else {
                if (cur -> right) {
                    cur = cur -> right;
                } else {
                    cur -> right = node;
                    break;
                }
            }
        }
        return root ? root : node;
    }
};

#endif /* _01_insert_into_bst_h */
