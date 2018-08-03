//
//  225_mystack.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _25_mystack_h
#define _25_mystack_h

class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tmp;
        tmp.push(x);
        while(!q.empty()){
            tmp.push(q.front());
            q.pop();
        }
        q = tmp;
     }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

#endif /* _25_mystack_h */
