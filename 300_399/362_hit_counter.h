//
//  362_hit_counter.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _62_hit_counter_h
#define _62_hit_counter_h

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {}
    
    /** Record a hit.
     @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
     @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front() >= 300) {
            q.pop();
        }
        return q.size();
    }
    
private:
    queue<int> q;
};

#endif /* _62_hit_counter_h */
