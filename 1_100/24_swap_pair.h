//
//  24_swap_pair.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/19.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _4_swap_pair_h
#define _4_swap_pair_h

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummy(-1);
        ListNode *front = head, *tail = head;
        
        for(ListNode *p=&dummy; front != nullptr; p=p->next, tail=front){
            if(front->next != nullptr){
                front = front->next->next;
                p->next = tail->next;
                p = p->next;
                p->next = tail;
            } else {
                p->next = tail;
                break;
            }
            
            if(front == nullptr){
                p = p->next;
                p->next = nullptr;
                break;
            }
        }
        
        return dummy.next;
    }
};

#endif /* _4_swap_pair_h */
