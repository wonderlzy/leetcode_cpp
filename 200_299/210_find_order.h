//
//  210_find_order.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _10_find_order_h
#define _10_find_order_h

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if(numCourses <= 0) return res;
        
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        
        for(auto a : prerequisites){
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        
        queue<int> q;
        
        for(int i=0; i<numCourses; ++i){
            if(in[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int t = q.front();
            res.push_back(t);
            q.pop();
            
            for(auto a : graph[t]){
                --in[a];
                if(in[a] == 0)
                    q.push(a);
            }
        }
        
        if(res.size() != numCourses)
            res.clear();
        
        return res;
    }
};

#endif /* _10_find_order_h */
