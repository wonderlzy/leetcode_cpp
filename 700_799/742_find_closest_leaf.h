//
//  742_find_closest_leaf.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _42_find_closest_leaf_h
#define _42_find_closest_leaf_h

class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> back;
        TreeNode *kNode = find(root, k, back);
        queue<TreeNode*> q{{kNode}};
        unordered_set<TreeNode*> visited{{kNode}};
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (!t->left && !t->right) return t->val;
            if (t->left && !visited.count(t->left)) {
                visited.insert(t->left);
                q.push(t->left);
            }
            if (t->right && !visited.count(t->right)) {
                visited.insert(t->right);
                q.push(t->right);
            }
            if (back.count(t) && !visited.count(back[t])) {
                visited.insert(back[t]);
                q.push(back[t]);
            }
        }
        return -1;
    }
    TreeNode* find(TreeNode* node, int k, unordered_map<TreeNode*, TreeNode*>& back) {
        if (node->val == k) return node;
        if (node->left) {
            back[node->left] = node;
            TreeNode *left = find(node->left, k, back);
            if (left) return left;
        }
        if (node->right) {
            back[node->right] = node;
            TreeNode *right = find(node->right, k, back);
            if (right) return right;
        }
        return NULL;
    }
};

#endif /* _42_find_closest_leaf_h */
