//
//  606_tree_2string.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _06_tree_2string_h
#define _06_tree_2string_h

class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string res = "";
        helper(t, res);
        return string(res.begin() + 1, res.end() - 1);
    }
    void helper(TreeNode* t, string& res) {
        if (!t) return;
        res += "(" + to_string(t->val);
        if (!t->left && t->right) res += "()";
        helper(t->left, res);
        helper(t->right, res);
        res += ")";
    }
};

#endif /* _06_tree_2string_h */
