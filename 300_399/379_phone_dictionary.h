//
//  379_phone_dictionary.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _79_phone_dictionary_h
#define _79_phone_dictionary_h

class PhoneDirectory {
public:
    /** Initialize your data structure here
     @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        max_num = maxNumbers;
        next = idx = 0;
        recycle.resize(max_num);
        flag.resize(max_num, 1);
    }
    
    /** Provide a number which is not assigned to anyone.
     @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (next == max_num && idx <= 0) return -1;
        if (idx > 0) {
            int t = recycle[--idx];
            flag[t] = 0;
            return t;
        }
        flag[next] = false;
        return next++;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return number >= 0 && number < max_num && flag[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number < max_num && !flag[number]) {
            recycle[idx++] = number;
            flag[number] = 1;
        }
    }
private:
    int max_num, next, idx;
    vector<int> recycle, flag;
};

#endif /* _79_phone_dictionary_h */
