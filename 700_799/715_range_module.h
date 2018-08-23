//
//  715_range_module.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _15_range_module_h
#define _15_range_module_h

class RangeModule {
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        vector<pair<int, int>> res;
        int n = v.size(), cur = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i].second < left) {
                res.push_back(v[i]);
                ++cur;
            } else if (v[i].first > right) {
                res.push_back(v[i]);
            } else {
                left = min(left, v[i].first);
                right = max(right, v[i].second);
            }
        }
        res.insert(res.begin() + cur, {left, right});
        v = res;
    }
    
    bool queryRange(int left, int right) {
        for (auto a : v) {
            if (a.first <= left && a.second >= right) return true;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        vector<pair<int, int>> res, t;
        int n = v.size(), cur = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i].second <= left) {
                res.push_back(v[i]);
                ++cur;
            } else if (v[i].first >= right) {
                res.push_back(v[i]);
            } else {
                if (v[i].first < left) {
                    t.push_back({v[i].first, left});
                }
                if (v[i].second > right) {
                    t.push_back({right, v[i].second});
                }
            }
        }
        res.insert(res.begin() + cur, t.begin(), t.end());
        v = res;
    }
    
private:
    vector<pair<int, int>> v;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */

#endif /* _15_range_module_h */
