//
//  25_reverseKGroup.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _5_reverseKGroup_h
#define _5_reverseKGroup_h


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k<=1)
            return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        
        for(ListNode *prev=&dummy, *end=head; end; end=prev->next){
            for(int i=1; i<k && end!=nullptr; ++i)
                end = end->next;
            
            if(end == nullptr) break;
            
            prev = reverseList(prev, prev->next, end);
        }
        
        return dummy.next;
    }
    
    ListNode* reverseList(ListNode *prev, ListNode *begin, ListNode *end){
        ListNode *end_next = end->next, *cur = begin;
        ListNode *tmp = nullptr;
        while(cur != end){
            tmp = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = tmp;
        }
        end->next = prev->next;
        prev->next = end;
        begin->next = end_next;
        
        return begin;
    }
};

#endif /* _5_reverseKGroup_h */
