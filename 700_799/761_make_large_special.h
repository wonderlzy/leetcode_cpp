//
//  761_make_large_special.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _61_make_large_special_h
#define _61_make_large_special_h

class Solution {
public:
    string makeLargestSpecial(string S) {
        int cnt = 0, i = 0;
        vector<string> v;
        string res = "";
        for (int j = 0; j < S.size(); ++j) {
            cnt += (S[j] == '1') ? 1 : -1;
            if (cnt == 0) {
                v.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        for (int i = 0; i < v.size(); ++i) res += v[i];
        return res;
    }
};

#endif /* _61_make_large_special_h */
