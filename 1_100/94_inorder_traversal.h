//
//  94_inorder_traversal.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/10.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _4_inorder_traversal_h
#define _4_inorder_traversal_h


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *cur, *pre;
        cur = root;
        while (cur) {
            if (cur->left == NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right!=NULL && pre->right != cur)
                    pre = pre->right;
                
                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
        
        /*
        if(root == NULL) return {};
        stack<TreeNode*> s;
        vector<int> result;
        TreeNode* p = root;
        while(!s.empty() || p != NULL){
            if(p != NULL){
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                result.push_back(s.top()->val);
                s.pop();
                p = p->right;
            }
        }
        
        return result;
         
         */
        /*
        vector<int> result;
        recursive(root, result);
        
        return result;
         */
    }
    
private:
    void recursive(TreeNode* root, vector<int>& result){
        if(root == NULL)
            return ;
        recursive(root->left, result);
        result.push_back(root->val);
        recursive(root->right, result);
    }
};

#endif /* _4_inorder_traversal_h */
