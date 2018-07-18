//
//  100_is_same_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _00_is_same_tree_h
#define _00_is_same_tree_h


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        
        return (p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

#endif /* _00_is_same_tree_h */
