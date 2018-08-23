//
//  637_average_level.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _37_average_level_h
#define _37_average_level_h

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int n = q.size();
            double sum = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode *t = q.front(); q.pop();
                sum += t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(sum / n);
        }
        return res;
    }
};

#endif /* _37_average_level_h */
