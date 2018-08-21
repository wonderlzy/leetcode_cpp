//
//  538_convert_bst.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _38_convert_bst_h
#define _38_convert_bst_h

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
        
        /*
        if (!root) return NULL;
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->right;
            }
            p = st.top(); st.pop();
            p->val += sum;
            sum = p->val;
            p = p->left;
        }
        return root;
        */
    }
    void helper(TreeNode*& node, int& sum) {
        if (!node) return;
        helper(node->right, sum);
        node->val += sum;
        sum = node->val;
        helper(node->left, sum);
    }
    
};

#endif /* _38_convert_bst_h */
