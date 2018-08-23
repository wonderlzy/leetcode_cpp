//
//  690_get_importance.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _90_get_importance_h
#define _90_get_importance_h

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_set<int> s;
        unordered_map<int, Employee*> m;
        for (auto e : employees) m[e->id] = e;
        return helper(id, m, s);
    }
    int helper(int id, unordered_map<int, Employee*>& m, unordered_set<int>& s) {
        if (s.count(id)) return 0;
        s.insert(id);
        int res = m[id]->importance;
        for (int num : m[id]->subordinates) {
            res += helper(num, m, s);
        }
        return res;
    }
};

#endif /* _90_get_importance_h */
