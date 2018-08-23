//
//  706_hash_map.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _06_hash_map_h
#define _06_hash_map_h

class MyHashMap {
public:
private:
    int elements[1000001];
public:
    MyHashMap() {
        memset(elements, -1, 1000001);
    }
    
    void put(int key, int value) {
        elements[key] = value;
    }
    
    int get(int key) {
        return elements[key];
    }
    
    void remove(int key) {
        elements[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

#endif /* _06_hash_map_h */
