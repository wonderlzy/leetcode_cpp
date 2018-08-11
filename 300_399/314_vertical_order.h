//
//  314_vertical_order.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _14_vertical_order_h
#define _14_vertical_order_h

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()) {
            auto a = q.front(); q.pop();
            m[a.first].push_back(a.second->val);
            if (a.second->left) q.push({a.first - 1, a.second->left});
            if (a.second->right) q.push({a.first + 1, a.second->right});
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};

#endif /* _14_vertical_order_h */
