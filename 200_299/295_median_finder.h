//
//  295_median_finder.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _95_median_finder_h
#define _95_median_finder_h

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size() < large.size()){
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        
        return (small.size() > large.size()) ? small.top() : 0.5 * (small.top() - large.top());
    }
private:
    priority_queue<int> large, small;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

#endif /* _95_median_finder_h */
