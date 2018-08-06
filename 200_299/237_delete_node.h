//
//  237_delete_node.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _37_delete_node_h
#define _37_delete_node_h

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* tmp = node->next;
        node->next = tmp->next;
        delete tmp;
    }
};

#endif /* _37_delete_node_h */
