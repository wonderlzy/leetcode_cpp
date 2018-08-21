//
//  551_check_records.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _51_check_records_h
#define _51_check_records_h

class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0, cntL = 0;
        for (char c : s) {
            if (c == 'A') {
                if (++cntA > 1) return false;
                cntL = 0;
            } else if (c == 'L') {
                if (++cntL > 2) return false;
            } else {
                cntL = 0;
            }
        }
        return true;
        
        /*
        return (s.find("A") == string::npos || s.find("A") == s.rfind("A")) && s.find("LLL") == string::npos;
        */
    }
};

#endif /* _51_check_records_h */
