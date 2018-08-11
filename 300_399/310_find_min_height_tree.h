//
//  310_find_min_height_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _10_find_min_height_tree_h
#define _10_find_min_height_tree_h

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n==1) return {0};
        vector<int> res;
        vector<unordered_set<int>> adj(n);
        queue<int> q;
        
        for(auto edge : edges){
            adj[edge.first].insert(edge.second);
            adj[edge.second].insert(edge.first);
        }
        
        for(int i=0; i<n; ++i){
            if(adj[i].size() == 1)
                q.push(i);
        }
        
        while(n > 2){
            size_t size = q.size();
            n -= size;
            for(int i=0; i<size; ++i){
                int t = q.front();
                q.pop();
                
                for(auto a : adj[t]){
                    adj[a].erase(t);
                    if(adj[a].size() == 1)
                        q.push(a);
                }
            }
        }
        
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};

#endif /* _10_find_min_height_tree_h */
