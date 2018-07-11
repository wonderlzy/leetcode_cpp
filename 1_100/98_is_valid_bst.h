//
//  98_is_valid_bst.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _8_is_valid_bst_h
#define _8_is_valid_bst_h


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool isValidBST(TreeNode* root, long lower, long upper){
        if(root == NULL)
            return true;
        return root->val>lower && root->val<upper && isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
};

#endif /* _8_is_valid_bst_h */
