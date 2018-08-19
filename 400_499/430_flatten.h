//
//  430_flatten.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/18.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _30_flatten_h
#define _30_flatten_h

/*
 // Definition for a Node.
 class Node {
 public:
 int val = NULL;
 Node* prev = NULL;
 Node* next = NULL;
 Node* child = NULL;
 
 Node() {}
 
 Node(int _val, Node* _prev, Node* _next, Node* _child) {
 val = _val;
 prev = _prev;
 next = _next;
 child = _child;
 }
 };
 */
class Solution {
public:
    bool dfs(Node *head,vector<Node *> &path){
        if(head == NULL){
            return false;
        }
        
        path.push_back(head);
        if(head->child){
            dfs(head->child,path);
        }
        dfs(head->next,path);
        
        return true;
    }
    
    Node* flatten(Node* head) {
        Node * node = head;
        vector<Node *> path;
        dfs(head,path);
        
        if(!head){
            return NULL;
        }
        
        for(int i = 1;i < path.size(); ++i){
            node->next = path[i];
            node->child = NULL;
            path[i]->prev = node;
            node = path[i];
        }
        
        node->next = NULL;
        node->child = NULL;
        
        return head;
    }
    
    /*
     Node* getTail(Node* head) { /* 获取尾节点 */
    Node* now = head;
    while (now->next) {
        now = now->next;
    }
    return now;
}

Node* flatten(Node* head) {
    Node* now = head;
    while (now) {
        if (now->child) {
            Node* subHead = flatten(now->child); /* 递归获取展开后的子序列的头节点 */
            Node* subTail = getTail(subHead); /* 获取子序列的尾节点 */
            Node* nowNext = now->next;
            now->child = nullptr; /* 断开儿子节点 */
            /* 将当前节点与子序列的头部进行链接 */
            now->next = subHead;
            subHead->prev = now;
            /* 若当前节点存在后驱，则要将当前节点的后驱与子序列的尾部链接 */
            if (nowNext) {
                nowNext->prev = subTail;
                subTail->next = nowNext;
            }
        }
        now = now->next;
    }
    return head;
}
     */
};

#endif /* _30_flatten_h */
