//
//  281_zigzag_iterator.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _81_zigzag_iterator_h
#define _81_zigzag_iterator_h

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.push_back(v1);
        v.push_back(v2);
        i = j = 0;
    }
    int next() {
        return i <= j ? v[0][i++] : v[1][j++];
    }
    bool hasNext() {
        if (i >= v[0].size()) i = INT_MAX;
        if (j >= v[1].size()) j = INT_MAX;
        return i < v[0].size() || j < v[1].size();
    }
private:
    vector<vector<int>> v;
    int i, j;
};

#endif /* _81_zigzag_iterator_h */
