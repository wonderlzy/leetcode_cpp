//
//  173_bst_iterator.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _73_bst_iterator_h
#define _73_bst_iterator_h

#include "base_structure.h"

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = s.top();
        s.pop();
        int res = tmp->val;
        if(tmp->right){
            tmp = tmp->right;
            while(tmp){
                s.push(tmp);
                tmp = tmp->left;
            }
        }
        
        return res;
    }
    
private:
    stack<TreeNode*> s;
};

#endif /* _73_bst_iterator_h */
