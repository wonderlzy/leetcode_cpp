//
//  558_intersect.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _58_intersect_h
#define _58_intersect_h

/*
 // Definition for a QuadTree node.
 class Node {
 public:
 bool val;
 bool isLeaf;
 Node* topLeft;
 Node* topRight;
 Node* bottomLeft;
 Node* bottomRight;
 
 Node() {}
 
 Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
 val = _val;
 isLeaf = _isLeaf;
 topLeft = _topLeft;
 topRight = _topRight;
 bottomLeft = _bottomLeft;
 bottomRight = _bottomRight;
 }
 };
 */
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf && quadTree1->val) return quadTree1;
        if(quadTree2->isLeaf && quadTree2->val) return quadTree2;
        if(quadTree1->isLeaf && !quadTree1->val) return quadTree2;
        if(quadTree2->isLeaf && !quadTree2->val) return quadTree1;
        
        auto tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        auto tr = intersect(quadTree1->topRight, quadTree2->topRight);
        auto bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        auto br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        
        if(tl->val == tr->val && tl->val == bl->val && tl->val == br->val && tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf)
            return new Node(tl->val, true, nullptr, nullptr, nullptr, nullptr);
        else
            return new Node(false, false, tl, tr, bl, br);
    }
};

#endif /* _58_intersect_h */
