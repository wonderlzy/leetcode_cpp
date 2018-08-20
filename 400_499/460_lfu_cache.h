//
//  460_lfu_cache.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _60_lfu_cache_h
#define _60_lfu_cache_h

public:
LFUCache(int capacity) {
    cap = capacity;
}

int get(int key) {
    if (m.count(key) == 0) return -1;
    freq[m[key].second].erase(iter[key]);
    ++m[key].second;
    freq[m[key].second].push_back(key);
    iter[key] = --freq[m[key].second].end();
    if (freq[minFreq].size() == 0) ++minFreq;
    return m[key].first;
}

void put(int key, int value) {
    if (cap <= 0) return;
    if (get(key) != -1) {
        m[key].first = value;
        return;
    }
    if (m.size() >= cap) {
        m.erase(freq[minFreq].front());
        iter.erase(freq[minFreq].front());
        freq[minFreq].pop_front();
    }
    m[key] = {value, 1};
    freq[1].push_back(key);
    iter[key] = --freq[1].end();
    minFreq = 1;
}

private:
int cap, minFreq;
unordered_map<int, pair<int, int>> m;
unordered_map<int, list<int>> freq;
unordered_map<int, list<int>::iterator> iter;

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

#endif /* _60_lfu_cache_h */
