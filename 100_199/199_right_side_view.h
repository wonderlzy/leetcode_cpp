//
//  199_right_side_view.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _99_right_side_view_h
#define _99_right_side_view_h

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            res.push_back(q.back()->val);
            
            size_t size = q.size();
            for(size_t i=0; i<size; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};

#endif /* _99_right_side_view_h */
