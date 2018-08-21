//
//  589_NTree_preorder.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _89_NTree_preorder_h
#define _89_NTree_preorder_h

#include "../base_structure.h"
class Solution {
public:
    vector<int> preorder(Node* root) {
        /*
        if(!root)
            return vector<int>();
        vector<int> res;
        res.push_back(root->val);
        for(int i(0);i<root->children.size();i++){
            vector<int> cur=preorder(root->children[i]);
            if(cur.size()>0)
                res.insert(res.end(),cur.begin(),cur.end());
        }
        return res;
        */
        
        vector<int> v;
        stack<Node*> s;
        if (!root) return v;
        if (root->children.size() == 0) {
            v.push_back(root->val);
            return v;
        }
        s.push(root);
        while (s.size() > 0) {
            Node* c = s.top();
            s.pop();
            v.push_back(c->val);
            for (int i = c->children.size() - 1; c != nullptr && i > -1; i--) {
                s.push(c->children[i]);
            }
        }
        return v;
    }
};

#endif /* _89_NTree_preorder_h */
