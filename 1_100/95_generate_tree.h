//
//  95_generate_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/10.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _5_generate_tree_h
#define _5_generate_tree_h


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n==0) return {};
        return generate(1, n);
    }
    
private:
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> subTree;
        if(start > end){
            subTree.push_back(NULL);
            return subTree;
        }
        
        for(int k=start; k<=end; ++k){
            vector<TreeNode*> left = generate(start, k-1);
            vector<TreeNode*> right = generate(k+1, end);
            
            for(auto i : left){
                for(auto j: right){
                    TreeNode* node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
        }
        
        return subTree;
    }
};

#endif /* _5_generate_tree_h */
