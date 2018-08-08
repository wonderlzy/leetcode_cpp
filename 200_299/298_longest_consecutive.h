//
//  298_longest_consecutive.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/8.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _98_longest_consecutive_h
#define _98_longest_consecutive_h

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, root->val, 0, res);
        return res;
    }
    void dfs(TreeNode *root, int v, int out, int &res) {
        if (!root) return;
        if (root->val == v + 1) ++out;
        else out = 1;
        res = max(res, out);
        dfs(root->left, root->val, out, res);
        dfs(root->right, root->val, out, res);
    }
};

#endif /* _98_longest_consecutive_h */
