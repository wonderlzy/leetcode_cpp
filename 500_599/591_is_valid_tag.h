//
//  591_is_valid_tab.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018年 zhongyingli. All rights reserved.
//

#ifndef _91_is_valid_tab_h
#define _91_is_valid_tab_h

class Solution {
public:
    bool isValid(string code) {
        regex cdata("<!\\[CDATA\\[.*?\\]\\]>"), tag("<([A-Z]{1,9})>[^<]*</\\1>");
        code = regex_replace(code, cdata, "c");
        string pre = code;
        while ( pre != (code = regex_replace(code, tag, "t")) )
            pre = code;
        return "t" == code;
    }
};

#endif /* _91_is_valid_tab_h */
