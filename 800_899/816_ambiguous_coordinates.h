//
//  816_ambiguous_coordinates.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _16_ambiguous_coordinates_h
#define _16_ambiguous_coordinates_h

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        int n = S.size();
        vector<string> res;
        for (int i = 1; i < n - 2; ++i) {
            vector<string> A = f(S.substr(1, i)), B = f(S.substr(i + 1, n - 2 - i));
            for (auto & a : A) for (auto & b : B) res.push_back("(" + a + ", " + b + ")");
        }
        return res;
    }
    vector<string> f(string S) {
        int n = S.size();
        if (n == 0 || (n > 1 && S[0] == '0' && S[n - 1] == '0')) return {};
        if (n > 1 && S[0] == '0') return {"0." + S.substr(1)};
        if (n == 1 || S[n - 1] == '0') return {S};
        vector<string> res = {S};
        for (int i = 1; i < n; ++i) res.push_back(S.substr(0, i) + '.' + S.substr(i));
        return res;
    }
};

#endif /* _16_ambiguous_coordinates_h */
