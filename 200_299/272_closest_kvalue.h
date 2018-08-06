//
//  272_closest_kvalue.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _72_closest_kvalue_h
#define _72_closest_kvalue_h

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inorder(root, target, k, res);
        return res;
    }
    void inorder(TreeNode *root, double target, int k, vector<int> &res) {
        if (!root) return;
        inorder(root->left, target, k, res);
        if (res.size() < k) res.push_back(root->val);
        else if (abs(root->val - target) < abs(res[0] - target)) {
            res.erase(res.begin());
            res.push_back(root->val);
        } else return;
        inorder(root->right, target, k, res);
    }
};

#endif /* _72_closest_kvalue_h */
