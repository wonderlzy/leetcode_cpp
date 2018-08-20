//
//  501_find_mode.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _01_find_mode_h
#define _01_find_mode_h

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int mx = 0, cnt = 1;
        TreeNode *pre = NULL;
        inorder(root, pre, cnt, mx, res);
        return res;
    }
    void inorder(TreeNode* node, TreeNode*& pre, int& cnt, int& mx, vector<int>& res) {
        if (!node) return;
        inorder(node->left, pre, cnt, mx, res);
        if (pre) {
            cnt = (node->val == pre->val) ? cnt + 1 : 1;
        }
        if (cnt >= mx) {
            if (cnt > mx) res.clear();
            res.push_back(node->val);
            mx = cnt;
        }
        pre = node;
        inorder(node->right, pre, cnt, mx, res);
    }
    /*
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int mx = 0;
        unordered_map<int, int> m;
        inorder(root, m, mx);
        for (auto a : m) {
            if (a.second == mx) {
                res.push_back(a.first);
            }
        }
        return res;
    }
    void inorder(TreeNode* node, unordered_map<int, int>& m, int& mx) {
        if (!node) return;
        inorder(node->left, m, mx);
        mx = max(mx, ++m[node->val]);
        inorder(node->right, m, mx);
    }
    */
};

#endif /* _01_find_mode_h */
