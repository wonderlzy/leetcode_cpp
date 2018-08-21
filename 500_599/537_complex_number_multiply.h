//
//  537_complex_number_multiply.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _37_complex_number_multiply_h
#define _37_complex_number_multiply_h

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        auto p1 = a.find_last_of("+"), p2 = b.find_last_of("+");
        int a1 = stoi(a.substr(0, p1)), b1 = stoi(b.substr(0, p2));
        int a2 = stoi(a.substr(p1 + 1, n1 - p1 - 2));
        int b2 = stoi(b.substr(p2 + 1, n2 - p2 - 2));
        int r1 = a1 * b1 - a2 * b2, r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
        
        /*
        istringstream is1(a), is2(b);
        int a1, a2, b1, b2, r1, r2;
        char plus;
        is1 >> a1 >> plus >> a2;
        is2 >> b1 >> plus >> b2;
        r1 = a1 * b1 - a2 * b2, r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
         */
    }
};

#endif /* _37_complex_number_multiply_h */
