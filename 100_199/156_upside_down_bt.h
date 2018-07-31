//
//  156_upside_down_bt.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018年 zhongyingli. All rights reserved.
//

#ifndef _56_upside_down_bt_h
#define _56_upside_down_bt_h

#include "base_structure.h"
class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        TreeNode *cur = root, *pre = NULL, *next = NULL, *tmp = NULL;
        while (cur) {
            next = cur->left;
            cur->left = tmp;
            tmp = cur->right;
            cur->right = pre;
            pre = cur;
            cur = next;
        }
        return pre;
        
        /*
        if(!root || !root->left) return root;
        
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        
        TreeNode *res = upsideDownBinaryTree(l);
        
        l->left = r;
        l->right = root;
        root->left = NULL;
        root->right = NULL;
        
        return res;
         */
    }
};

#endif /* _56_upside_down_bt_h */
