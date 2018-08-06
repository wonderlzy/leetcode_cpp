//
//  285_in_order_successor.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _85_in_order_successor_h
#define _85_in_order_successor_h

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        bool b = false;
        TreeNode *t = root;
        while (t || !s.empty()) {
            while (t) {
                s.push(t);
                t = t->left;
            }
            t = s.top(); s.pop();
            if (b) return t;
            if (t == p) b = true;
            t = t->right;
        }
        return NULL;
    }
};


#endif /* _85_in_order_successor_h */
