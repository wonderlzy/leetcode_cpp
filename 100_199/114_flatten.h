//
//  114_flatten.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/19.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _14_flatten_h
#define _14_flatten_h

#include "base_structure.h"
class Solution {
public:
    void flatten(TreeNode* root) {
        /*
        if(!root) return;
        if(root->left)
            flatten(root->left);
        if(root->right)
            flatten(root->right);
        
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        while(root->right)
            root = root->right;
        
        root->right = tmp;
        */
        flatten(root, NULL);
    }
private:
    TreeNode* flatten(TreeNode* root, TreeNode* tail){
        if(!root) return tail;
        
        root->right = flatten(root->left, flatten(root->right, tail));
        root->left = NULL;
        
        return root;
    }
};

#endif /* _14_flatten_h */
