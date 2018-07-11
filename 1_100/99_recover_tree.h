//
//  99_recover_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _9_recover_tree_h
#define _9_recover_tree_h


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL, *second = NULL, *parent = NULL;
        TreeNode* cur, *pre;
        cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                if(parent!=NULL && parent->val > cur->val){
                    if(first == NULL) first = parent;
                    second = cur;
                }
                parent = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                while(pre->right != NULL && pre->right != cur)
                    pre = pre->right;
                
                if(pre->right == NULL){
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    if(parent->val > cur->val){
                        if(first == NULL) first = parent;
                        second = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        
        if(first!=NULL && second!=NULL) swap(first->val, second->val);
    }
};

#endif /* _9_recover_tree_h */
