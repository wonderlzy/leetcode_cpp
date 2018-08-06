//
//  257_binary_tree_paths.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _57_binary_tree_paths_h
#define _57_binary_tree_paths_h

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root) helper(root, res, "");
        return res;
    }
    
    void helper(TreeNode* root, vector<string>& result, string out){
        if(!root->left && !root->right)
            result.push_back(out+to_string(root->val));
        if(root->left) helper(root->left, result, out+to_string(root->val)+"->");
        if(root->right) helper(root->right, result, out+to_string(root->val)+"->");
    }
};

#endif /* _57_binary_tree_paths_h */
