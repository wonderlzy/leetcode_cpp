//
//  481_magic_string.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _81_magic_string_h
#define _81_magic_string_h

class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while (s.size() < n) {
            s += string(s[i++] - '0', s.back() ^ 3);
        }
        return count(s.begin(), s.begin() + n, '1');
        /*
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        int res = 1, head = 2, tail = 3, num = 1;
        vector<int> v{1, 2, 2};
        while (tail < n) {
            for (int i = 0; i < v[head]; ++i) {
                v.push_back(num);
                if (num == 1 && tail < n) ++res;
                ++tail;
            }
            num ^= 3;
            ++head;
        }
        return res;
        */
    }
};

#endif /* _81_magic_string_h */
