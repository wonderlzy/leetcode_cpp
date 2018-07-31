//
//  155_min_stack.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _55_min_stack_h
#define _55_min_stack_h

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int x) {
        if(x <= minVal){
            st.push(minVal);
            minVal = x;
        }
        st.push(x);
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        if(top == minVal){
            minVal = st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }
private:
    int minVal;
    stack<int> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

#endif /* _55_min_stack_h */
