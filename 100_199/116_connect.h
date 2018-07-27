//
//  116_connect.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/27.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _16_connect_h
#define _16_connect_h

#include "base_structure.h"
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return ;
        TreeLinkNode* start = root;
        TreeLinkNode* cur = NULL;
        
        while(start->left){
            cur = start;
            
            while(cur){
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            
            start = start->left;
        }
        
        /*
        if(!root) return ;
        if(root->left)
            root->left->next = root->right;
        if(root->right)
            root->right->next = root->next ? root->next->left : NULL;
        
        connect(root->left);
        connect(root->right);
        */
        
        /*
        recursive(root, NULL);
        */
    }
private:
    void recursive(TreeLinkNode* root, TreeLinkNode* split){
        if(root == NULL) return ;
        else
            root->next = split;
        
        recursive(root->left, root->right);
        
        if(split)
            recursive(root->right, split->left);
        else
            recursive(root->right, NULL);
    }
};


#endif /* _16_connect_h */
