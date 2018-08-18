//
//  427_construct.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/18.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _27_construct_h
#define _27_construct_h

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
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }
    
    Node* construct(const vector<vector<int>>& grid, int x, int y, int n) {
        if (n == 0) return nullptr;
        bool all_zeros = true;
        bool all_ones = true;
        for (int i = y; i < y + n; ++i)
            for (int j = x; j < x + n; ++j)
                if (grid[i][j] == 0)
                    all_ones = false;
                else
                    all_zeros = false;
        if (all_zeros || all_ones)
            return new Node(all_ones, true, nullptr, nullptr, nullptr, nullptr);
        
        return new Node(true, false,
                        construct(grid, x,       y,       n/2),  // topLeft
                        construct(grid, x + n/2, y,       n/2),  // topRight
                        construct(grid, x,       y + n/2, n/2),  // bottomLeft
                        construct(grid, x + n/2, y + n/2, n/2)); // bottomRight
    }
};

#endif /* _27_construct_h */
