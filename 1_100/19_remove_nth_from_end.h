//
//  19_remove_nth_from_end.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/19.
//  Copyright © 2018年 zhongyingli. All rights reserved.
//

#ifndef _9_remove_nth_from_end_h
#define _9_remove_nth_from_end_h



 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *front = &dummy, *tail = &dummy;
        if(front == nullptr || n<=0) return front;
        int count = 0;
        
        while(front){
            front = front->next;
            if(++count > n)
                tail = tail->next;
        } // tail is prev of last Kth
        
        ListNode *tmp = tail->next;
        tail->next = tail->next->next;
        delete tmp;
        
        return dummy.next;
    }
};

#endif /* _9_remove_nth_from_end_h */
