//
//  103_zigzag_level_order.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _03_zigzag_level_order_h
#define _03_zigzag_level_order_h

#include "base_structure.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool positive = true;
        
        while(!dq.empty()){
            vector<int> level;
            size_t size = dq.size();
            if(positive){
                for(int i=0; i<size; ++i){
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    level.push_back(node->val);
                    
                    if(node->left) dq.push_back(node->left);
                    if(node->right) dq.push_back(node->right);
                    positive = false;
                }
            } else {
                for(int i=0; i<size; ++i){
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    level.push_back(node->val);
                    
                    if(node->right) dq.push_front(node->right);
                    if(node->left) dq.push_front(node->left);
                    positive = true;
                }
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};

#endif /* _03_zigzag_level_order_h */
