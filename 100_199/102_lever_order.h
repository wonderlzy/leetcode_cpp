//
//  102_lever_order.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _02_lever_order_h
#define _02_lever_order_h

#include "base_structure.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        traverse(root, result, 1);
        
        return result;
        /*
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> level;
            size_t size = q.size();
            for(size_t i=0; i<size; ++i){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(level);
        }
        
        return result;
         */
    }
    
private:
    void traverse(TreeNode* root, vector<vector<int>>& result, int level){
        if(!root) return ;
        if(level > result.size())
            result.push_back(vector<int>());
        result[level-1].push_back(root->val);
        traverse(root->left, result, level+1);
        traverse(root->right, result, level+1);
    }
};

#endif /* _02_lever_order_h */
