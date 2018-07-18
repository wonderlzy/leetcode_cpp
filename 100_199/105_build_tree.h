//
//  105_build_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _05_build_tree_h
#define _05_build_tree_h

#include "base_structure.h"
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return binaryBuid(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
private:
    template<typename InputIter>
    TreeNode* binaryBuid(InputIter pre_first, InputIter pre_last, InputIter in_first, InputIter in_last){
        if(pre_first == pre_last || in_first == in_last)
            return NULL;
        TreeNode* root = new TreeNode(*pre_first);
        auto pos = find(in_first, in_last, root->val);
        auto leftsize = distance(in_first, pos);
        
        root->left = binaryBuid(next(pre_first), next(pre_first,leftsize+1), in_first, next(in_first, leftsize));
        root->right = binaryBuid(next(pre_first, leftsize+1), pre_last, next(pos), in_last);
        
        return root;
    }
};

#endif /* _05_build_tree_h */
