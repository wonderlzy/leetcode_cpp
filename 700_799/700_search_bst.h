//
//  700_search_bst.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _00_search_bst_h
#define _00_search_bst_h

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) { return NULL; }
        if (root->val == val) { return root; }
        //Recursion
        if (root->val < val) { return searchBST(root->right, val); }
        if (root->val > val) { return searchBST(root->left, val); }
    }
};

#endif /* _00_search_bst_h */
