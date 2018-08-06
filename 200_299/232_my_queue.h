//
//  232_my_queue.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _32_my_queue_h
#define _32_my_queue_h

class MyQueue {
private:
    stack<int> s;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while(!s.empty()){
            tmp.push(s.top());
            s.pop();
        }
        
        s.push(x);
        while(!tmp.empty()){
            s.push(tmp.top());
            tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = s.top();
        s.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

#endif /* _32_my_queue_h */
