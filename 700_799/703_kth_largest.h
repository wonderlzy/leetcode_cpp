//
//  703_kth_largest.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _03_kth_largest_h
#define _03_kth_largest_h

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) :
    k_(k) {
        for (const auto& num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        min_heap_.emplace(val);
        if (min_heap_.size() > k_) {
            min_heap_.pop();
        }
        return min_heap_.top();
    }
    
private:
    const int k_;
    priority_queue<int, vector<int>, greater<int>> min_heap_;
};


#endif /* _03_kth_largest_h */
