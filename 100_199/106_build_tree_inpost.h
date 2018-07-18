//
//  106_build_tree_inpost.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _06_build_tree_inpost_h
#define _06_build_tree_inpost_h

#include "base_structure.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
private:
    template <typename Iter>
    TreeNode* build(Iter in_start, Iter in_end, Iter post_start, Iter post_end){
        if(in_start == in_end || post_start == post_end){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(*prev(post_end));
        auto pos = find(in_start, in_end, root->val);
        auto left_size = distance(in_start, pos);
        
        root->left = build(in_start, pos, post_start, next(post_start, left_size));
        root->right = build(next(pos), in_end, next(post_start, left_size), prev(post_end));
        
        return root;
    }
};

#endif /* _06_build_tree_inpost_h */
