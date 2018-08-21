//
//  604_compressed_string.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _04_compressed_string_h
#define _04_compressed_string_h

class StringIterator {
public:
    StringIterator(string compressedString) {
        is = istringstream(compressedString);
        cnt = 0;
        c = ' ';
    }
    
    char next() {
        if (hasNext()) {
            --cnt;
            return c;
        }
        return ' ';
    }
    
    bool hasNext() {
        if (cnt == 0) {
            is >> c >> cnt;
        }
        return cnt > 0;
    }
    
private:
    istringstream is;
    int cnt;
    char c;
};

#endif /* _04_compressed_string_h */
