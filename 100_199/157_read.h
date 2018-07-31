//
//  157_read.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _57_read_h
#define _57_read_h

int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int res = 0;
        for(int i=0; i<= n/4; ++i){
            int cur = read4(buf+res);
            if(cur == 0) break;
            res += cur;
        }
        return min(res, 0);
    }
};

#endif /* _57_read_h */
