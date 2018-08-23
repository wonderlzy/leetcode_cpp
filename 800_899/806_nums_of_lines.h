//
//  806_nums_of_lines.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _06_nums_of_lines_h
#define _06_nums_of_lines_h

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int cnt = 1, cur = 0;
        for (char c : S) {
            int t = widths[c - 'a'];
            if (cur + t > 100) ++cnt;
            cur = (cur + t > 100) ? t : cur + t;
        }
        return {cnt, cur};
    }
};

#endif /* _06_nums_of_lines_h */
