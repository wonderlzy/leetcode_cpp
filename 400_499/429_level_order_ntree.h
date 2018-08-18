//
//  429_level_order_ntree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/18.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _29_level_order_ntree_h
#define _29_level_order_ntree_h

/*
 // Definition for a Node.
 class Node {
 public:
 int val = NULL;
 vector<Node*> children;
 
 Node() {}
 
 Node(int _val, vector<Node*> _children) {
 val = _val;
 children = _children;
 }
 };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> tmp;
            int n=q.size();
            for(int i=0;i<n;++i){
                Node* t=q.front();q.pop();
                tmp.push_back(t->val);
                for(int j=0;j<t->children.size();++j){
                    q.push(t->children[j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

#endif /* _29_level_order_ntree_h */
