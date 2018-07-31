//
//  166_fraction_2decimal.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _66_fraction_2decimal_h
#define _66_fraction_2decimal_h

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        long long num = abs( (long long)numerator );
        long long den = abs( (long long)denominator );
        long long out = num / den;
        long long rem = num % den;
        unordered_map<long long, int> m;
        string res = to_string(out);
        if (s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;
        if (rem == 0) return res;
        res += ".";
        string s = "";
        int pos = 0;
        while (rem != 0) {
            if (m.find(rem) != m.end()) {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
            ++pos;
        }
        return res + s;
    }
};

#endif /* _66_fraction_2decimal_h */
