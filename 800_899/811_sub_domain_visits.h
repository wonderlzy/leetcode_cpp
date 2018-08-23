//
//  811_sub_domain_visits.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _11_sub_domain_visits_h
#define _11_sub_domain_visits_h

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> c;
        for (auto cd : cpdomains) {
            int i = cd.find(" ");
            int n = stoi(cd.substr (0, i));
            string s = cd.substr (i + 1, cd.size () - i - 1);
            for (int i = 0; i < s.size(); ++i) if (s[i] == '.') c[s.substr(i + 1, s.size () - i)] += n;
            c[s] += n;
        }
        vector<string> res;
        for (auto k : c) res.push_back (to_string(k.second) + " " + k.first);
        return res;
    }
};

#endif /* _11_sub_domain_visits_h */
