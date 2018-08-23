//
//  653_find_target.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _53_find_target_h
#define _53_find_target_h

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> s;
        return helper(root, k, s);
    }
    bool helper(TreeNode* node, int k, unordered_set<int>& s) {
        if (!node) return false;
        if (s.count(k - node->val)) return true;
        s.insert(node->val);
        return helper(node->left, k, s) || helper(node->right, k, s);
    }
};

#endif /* _53_find_target_h */
