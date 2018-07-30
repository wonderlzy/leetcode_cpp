//
//  145_post_order_traversal.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _45_post_order_traversal_h
#define _45_post_order_traversal_h

#include "base_structure.h"
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* head = root;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* tmp = s.top();
            if((!tmp->left && !tmp->right) || tmp->left == head || tmp->right == head){
                s.pop();
                head = tmp;
                res.push_back(tmp->val);
            } else {
                if(tmp->right) s.push(tmp->right);
                if(tmp->left) s.push(tmp->left);
            }
        }
        
        return res;
        
        /*
        vector<int> result;
        postOrder(root, result);
        
        return result;
        */
    }
    
private:
    void postOrder(TreeNode* root, vector<int>& result){
        if(!root) return ;
        
        if(root->left) postOrder(root->left, result);
        if(root->right) postOrder(root->right, result);
        result.push_back(root->val);
    }
};

#endif /* _45_post_order_traversal_h */
