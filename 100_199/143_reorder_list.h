//
//  143_reorder_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _43_reorder_list_h
#define _43_reorder_list_h

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return ;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = NULL;
        
        ListNode* last = mid;
        ListNode* pre = NULL;
        
        while(last){
            ListNode* tmp = last->next;
            last->next = pre;
            pre = last;
            last = tmp;
        }
        
        while(head && pre){
            ListNode* tmp = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = tmp;
            head = tmp;
        }
    }
};

#endif /* _43_reorder_list_h */
