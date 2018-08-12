//
//  366_find_leaves.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _66_find_leaves_h
#define _66_find_leaves_h

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
    int helper(TreeNode *root, vector<vector<int>> &res) {
        if (!root) return -1;
        int depth = 1 + max(helper(root->left, res), helper(root->right, res));
        if (depth >= res.size()) res.resize(depth + 1);
        res[depth].push_back(root->val);
        return depth;
    }
};

#endif /* _66_find_leaves_h */
