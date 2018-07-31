//
//  156_get_intersection_node.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _56_get_intersection_node_h
#define _56_get_intersection_node_h

#include "base_structure.h"
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* a = headA, *b = headB;
        
        while(a != b){
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        
        return a;
        
        /*
        if(!headA || !headB) return NULL;
        int lenA = 0, lenB = 0;
        ListNode* curA = headA, *curB = headB;
        while(curA){
            ++lenA;
            curA = curA->next;
        }
        while(curB){
            ++lenB;
            curB = curB->next;
        }
        
        curA = headA; curB = headB;
        
        while(lenA > lenB ){
            curA = curA->next;
            --lenA;
        }
        
        while(lenB > lenA){
            curB = curB->next;
            --lenB;
        }
        
        while(curA && curB){
            if(curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        
        return NULL;
        */
    }
};

#endif /* _56_get_intersection_node_h */
