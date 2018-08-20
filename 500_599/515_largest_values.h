//
//  515_largest_values.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _15_largest_values_h
#define _15_largest_values_h

#include "../base_structure.h"
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size(), mx = INT_MIN;
            for (int i = 0; i < n; ++i) {
                TreeNode *t = q.front(); q.pop();
                mx = max(mx, t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};

#endif /* _15_largest_values_h */
