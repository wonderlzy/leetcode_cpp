//
//  572_is_subtree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _72_is_subtree_h
#define _72_is_subtree_h

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (isSame(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
    
    /*
    bool isSubtree(TreeNode* s, TreeNode* t) {
        ostringstream os1, os2;
        serialize(s, os1);
        serialize(t, os2);
        return os1.str().find(os2.str()) != string::npos;
    }
    void serialize(TreeNode* node, ostringstream& os) {
        if (!node) os << ",#";
        else {
            os << "," << node->val;
            serialize(node->left, os);
            serialize(node->right, os);
        }
    }
     */
};

#endif /* _72_is_subtree_h */
