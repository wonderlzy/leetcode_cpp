//
//  117_connect_2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/27.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _17_connect_2_h
#define _17_connect_2_h

#include "base_structure.h"

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* dummy = new TreeLinkNode(0);
        TreeLinkNode* t = dummy;
        
        while(root){
            if(root->left){
                t->next = root->left;
                t = t->next;
            }
            
            if(root->right){
                t->next = root->right;
                t = t->next;
            }
            
            root = root->next;
            
            if(!root){
                t = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
        
        
        /*
        if (!root) return;
        TreeLinkNode *p = root->next;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) root->right->next = p;
        if (root->left) root->left->next = root->right ? root->right : p;
        
        connect(root->right);
        connect(root->left);
         */
    }
};

#endif /* _17_connect_2_h */
