//
//  815_num_buses_2destination.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _15_num_buses_2destination_h
#define _15_num_buses_2destination_h

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, unordered_set<int>> to_route;
        for (int i = 0; i < routes.size(); ++i) for (auto& j : routes[i]) to_route[j].insert(i);
        queue<pair<int, int>> bfs; bfs.push(make_pair(S, 0));
        unordered_set<int> seen = {S};
        while (!bfs.empty()) {
            int stop = bfs.front().first, bus = bfs.front().second;
            bfs.pop();
            if (stop == T) return bus;
            for (auto& route_i : to_route[stop]) {
                for (auto& next_stop : routes[route_i])
                    if (seen.find(next_stop) == seen.end()) {
                        seen.insert(next_stop);
                        bfs.push(make_pair(next_stop, bus + 1));
                    }
                routes[route_i].clear();
            }
        }
        return -1;
    }
};

#endif /* _15_num_buses_2destination_h */
