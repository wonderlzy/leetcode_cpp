#ifndef __2_add_two__numbers__h__
#define __2_add_two__numbers__h__

#include <iostream>
using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode header(-1);
        ListNode *pre = &header;
        int post = 0;

        for(ListNode *pa=l1, *pb=l2; pa!=nullptr || pb!=nullptr; 
            pa= (pa==nullptr ? 0 : pa->next), 
            pb= (pb==nullptr ? 0 : pb->next),
            pre = pre->next ){
                const int ai = (pa==nullptr ? 0 : pa->val);
                const int bi = (pb==nullptr ? 0 : pb->val);

                int value = (ai+bi+post) % 10;
                post = (ai+bi+post) / 10;

                pre->next = new ListNode(value);
        }

        if(post > 0)
            pre->next = new ListNode(post);
        
        return header.next;
    }
};

#endif

/*
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
