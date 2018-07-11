//
//  92_reverse_between.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/10.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _2_reverse_between_h
#define _2_reverse_between_h


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m<1 || m>n) return NULL;
        if(head == NULL) return head;
        
        ListNode result(-1);
        result.next = head;
        ListNode* pos = &result;
        
        for(int i=0; i<m-1; ++i)
            pos = pos->next;
        
        ListNode* tail = pos->next;
        ListNode* cur = tail->next;
        for(int i=m; i<n; ++i){
            tail->next = cur->next;
            ListNode* insert = pos->next;
            pos->next = cur;
            cur->next = insert;
            cur = tail->next;
        }
        
        return result.next;
    }
};

#endif /* _2_reverse_between_h */
