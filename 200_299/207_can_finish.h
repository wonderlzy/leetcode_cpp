//
//  207_can_finish.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _07_can_finish_h
#define _07_can_finish_h

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        
        for(auto edge : prerequisites){
            graph[edge.second].push_back(edge.first);
            ++in[edge.first];
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(in[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto a : graph[t]){
                --in[a];
                if(in[a] == 0)
                    q.push(a);
            }
        }
        
        for(int i=0; i<numCourses; ++i){
            if(in[i] != 0)
                return false;
        }
        
        return true;
    }
};

#endif /* _07_can_finish_h */
