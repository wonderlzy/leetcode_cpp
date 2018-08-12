//
//  359_logger.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _59_logger_h
#define _59_logger_h

class Logger {
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!m.count(message)) {
            m[message] = timestamp;
            return true;
        }
        if (timestamp - m[message] >= 10) {
            m[message] = timestamp;
            return true;
        }
        return false;
    }
    
private:
    unordered_map<string, int> m;
};

#endif /* _59_logger_h */
