//
//  708_insert_into_cyclic_sorted_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _08_insert_into_cyclic_sorted_list_h
#define _08_insert_into_cyclic_sorted_list_h

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            auto node = new Node(insertVal, nullptr);
            node->next = node;
            return node;
        }
        auto curr = head;
        while (true) {
            if (curr->val < curr->next->val) {
                if (curr->val <= insertVal &&
                    insertVal <= curr->next->val) {
                    insertAfter(curr, insertVal);
                    break;
                }
            } else if (curr->val > curr->next->val) {
                if (curr->val <= insertVal ||
                    insertVal <= curr->next->val) {
                    insertAfter(curr, insertVal);
                    break;
                }
            } else {
                if (curr->next == head) {
                    insertAfter(curr, insertVal);
                    break;
                }
            }
            curr = curr->next;
        }
        return head;
    }
    
private:
    void insertAfter(Node *node, int val) {
        node->next = new Node(val, node->next);
    }
};

#endif /* _08_insert_into_cyclic_sorted_list_h */
