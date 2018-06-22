//
//  21_merge_two_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/19.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _1_merge_two_list_h
#define _1_merge_two_list_h


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        
        for(; l1 != nullptr && l2 != nullptr; p=p->next){
            if(l1->val > l2->val){
                p->next = l2;
                l2 = l2->next;
            }
            else{
                p->next = l1;
                l1 = l1->next;
            }
        }
        
        p->next = (l1!=nullptr) ? l1 : l2;
        
        return dummy.next;
    }
};

#endif /* _1_merge_two_list_h */
