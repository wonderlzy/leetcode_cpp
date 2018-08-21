//
//  590_NTree_post_order.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _90_NTree_post_order_h
#define _90_NTree_post_order_h

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root==NULL) return {};
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            Node* temp=stk.top();
            stk.pop();
            for(int i=0;i<temp->children.size();i++)
                stk.push(temp->children[i]);
            res.push_back(temp->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif /* _90_NTree_post_order_h */
