//
//  133_clone_graph.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _33_clone_graph_h
#define _33_clone_graph_h

#include "base_structure.h"

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> umap;
        
        return clone(node, umap);
    }
    
private:
    UndirectedGraphNode* clone(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& umap){
        if(!node)
            return node;
        
        if(umap.count(node->label))
            return umap[node->label];
        
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        umap[node->label] = newNode;
        
        for(int i=0; i<node->neighbors.size(); ++i){
            (newNode->neighbors).push_back(clone(node->neighbors[i], umap));
        }
        
        return newNode;
    }
};

#endif /* _33_clone_graph_h */
