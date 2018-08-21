//
//  622_circular_queue.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _22_circular_queue_h
#define _22_circular_queue_h

class MyCircularQueue {
private:
    class Node {
    public:
        int val;
        Node* next;
        Node() {}
    };
    Node *front, *rear;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        Node* root = new Node();
        Node* cur = root;
        front = root;
        rear = nullptr;
        for(int i = 0; i < k - 1; i++)
        {
            Node* temp = new Node();
            cur -> next = temp;
            cur = temp;
        }
        cur -> next = root;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty())
            rear = front;
        else
            rear = rear -> next;
        rear -> val = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        if (front == rear)
            rear = nullptr;
        else
            front = front -> next;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : front -> val;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : rear -> val;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return rear == nullptr;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(isEmpty()) return false;
        return rear -> next == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

#endif /* _22_circular_queue_h */
