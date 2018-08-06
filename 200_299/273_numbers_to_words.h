//
//  273_numbers_to_words.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _73_numbers_to_words_h
#define _73_numbers_to_words_h

class Solution {
public:
    string numberToWords(int num) {
        string res = convertHundred(num % 1000);
        vector<string> v = {"Thousand", "Million", "Billion"};
        for (int i = 0; i < 3; ++i) {
            num /= 1000;
            res = num % 1000 ? convertHundred(num % 1000) + " " + v[i] + " " + res : res;
        }
        while (res.back() == ' ') res.pop_back();
        return res.empty() ? "Zero" : res;
    }
    string convertHundred(int num) {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        int a = num / 100, b = num % 100, c = num % 10;
        res = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
        if (a > 0) res = v1[a] + " Hundred" + (b ? " " + res : "");
        return res;
    }
};

#endif /* _73_numbers_to_words_h */
