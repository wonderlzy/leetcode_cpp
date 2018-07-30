//
//  144_preorder_traversal.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _44_preorder_traversal_h
#define _44_preorder_traversal_h

#include "base_structure.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p=root;
        vector<int> result;
        while(p!=NULL||!s.empty())
        {
            while(p!=NULL)
            {
                s.push(p);
                result.push_back(p->val);
                p=p->left;
            }
            if(!s.empty())
            {
                p=s.top();
                s.pop();
                p=p->right;
            }
        }
        return result;
        /*
        vector<int> result;
        if(!root) return result;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* tmp = s.top();
            s.pop();
            
            result.push_back(tmp->val);
            if(tmp->right) s.push(tmp->right);
            if(tmp->left) s.push(tmp->left);
        }
        
        return result;
        */
        /*
        vector<int> result;
        preOrder(root, result);
        return result;
         */
    }
private:
    void preOrder(TreeNode* root, vector<int>& result){
        if(!root) return ;
        result.push_back(root->val);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
};

#endif /* _44_preorder_traversal_h */
