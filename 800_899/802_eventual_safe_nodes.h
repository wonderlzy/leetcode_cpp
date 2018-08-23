//
//  802_eventual_safe_nodes.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _02_eventual_safe_nodes_h
#define _02_eventual_safe_nodes_h

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res, color(n); // 0 white, 1 gray, 2 black
        for (int i = 0; i < n; ++i) {
            if (helper(graph, i, color)) res.push_back(i);
        }
        return res;
    }
    bool helper(vector<vector<int>>& graph, int cur, vector<int>& color) {
        if (color[cur] > 0) return color[cur] == 2;
        color[cur] = 1;
        for (int i : graph[cur]) {
            if (color[i] == 2) continue;
            if (color[i] == 1 || !helper(graph, i, color)) {
                return false;
            }
        }
        color[cur] = 2;
        return true;
    }
};

#endif /* _02_eventual_safe_nodes_h */
