//
//  426_bst_to_double_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/18.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _26_bst_to_double_list_h
#define _26_bst_to_double_list_h

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        Node* cur = root;
        stack<Node*> stk;
        Node* head = NULL;
        Node* prev = NULL;
        while(cur || !stk.empty()){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            }else{
                cur = stk.top();
                stk.pop();
                if(!head) head = cur;
                if(prev){
                    prev->right = cur;
                    cur->left = prev;
                }
                prev = cur;
                cur = cur->right;
            }
        }
        head->left = prev;
        prev->right = head;
        return head;
    }
};

#endif /* _26_bst_to_double_list_h */
