//
//  530_get_minimum_difference.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _30_get_minimum_difference_h
#define _30_get_minimum_difference_h

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX, pre = -1;
        inorder(root, pre, res);
        return res;
    }
    void inorder(TreeNode* root, int& pre, int& res) {
        if (!root) return;
        inorder(root->left, pre, res);
        if (pre != -1) res = min(res, root->val - pre);
        pre = root->val;
        inorder(root->right, pre, res);
    }
    
    /*
    class Solution {
    public:
        int getMinimumDifference(TreeNode* root) {
            int res = INT_MAX, pre = -1;
            stack<TreeNode*> st;
            TreeNode *p = root;
            while (p || !st.empty()) {
                while (p) {
                    st.push(p);
                    p = p->left;
                }
                p = st.top(); st.pop();
                if (pre != -1) res = min(res, p->val - pre);
                pre = p->val;
                p = p->right;
            }
            return res;
        }
    };
    */
};

#endif /* _30_get_minimum_difference_h */
