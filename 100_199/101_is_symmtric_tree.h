//
//  101_is_symmtric_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _01_is_symmtric_tree_h
#define _01_is_symmtric_tree_h


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        
        while(!s.empty()){
            auto a = s.top();
            s.pop();
            auto b = s.top();
            s.pop();
            
            if(!a && !b) continue;
            if(!a || !b) return false;
            if(a->val != b->val) return false;
            
            s.push(a->left);
            s.push(b->right);
            
            s.push(a->right);
            s.push(b->left);
        }
        
        return true;
        /*
        if(!root) return true;
        return isSymmetric(root->left, root->right);
        */
    }
    
private:
    bool isSymmetric(TreeNode* pre, TreeNode* cur){
        if(!pre && !cur) return true;
        if(!pre || !cur) return false;
        
        
        return (pre->val==cur->val) && isSymmetric(pre->left, cur->right) && isSymmetric(pre->right, cur->left);
    }
};

#endif /* _01_is_symmtric_tree_h */
