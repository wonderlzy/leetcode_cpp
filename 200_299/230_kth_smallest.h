//
//  230_kth_smallest.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _30_kth_smallest_h
#define _30_kth_smallest_h

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p = p->left;
            }
            
            p = s.top();
            s.pop();
            ++cnt;
            if(cnt == k) return p->val;
            p = p->right;
        }
        
        return 0;
    }
};

#endif /* _30_kth_smallest_h */
