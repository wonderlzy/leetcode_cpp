//
//  82_delete_duplicates.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _2_delete_duplicates_h
#define _2_delete_duplicates_h


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode result(-1);
        
        ListNode* pindex = head;
        ListNode* pAdd = head;
        ListNode* pcur = &result;
        int curCnt = 1;
        
        for(pindex=pindex->next; pindex != NULL; pindex=pindex->next){
            if(pindex->val == pAdd->val){
                ++curCnt;
                continue;
            }
            else {
                if(curCnt == 1){
                    pcur->next = pAdd;
                    pcur = pcur->next;
                    pcur->next = NULL;
                }
                
                curCnt = 1;
                pAdd = pindex;
            }
        }
        if(curCnt == 1){
            pcur->next = pAdd;
            pcur = pcur->next;
            pcur->next = NULL;
        }
        
        return result.next;
    }
};

#endif /* _2_delete_duplicates_h */
