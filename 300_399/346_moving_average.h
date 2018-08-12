//
//  346_moving_average.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _46_moving_average_h
#define _46_moving_average_h

class MovingAverage {
public:
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        if (q.size() >= size) {
            sum -= q.front(); q.pop();
        }
        q.push(val);
        sum += val;
        return sum / q.size();
    }
    
private:
    queue<int> q;
    int size;
    double sum;
};

#endif /* _46_moving_average_h */
