//
//  745_word_filter.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _45_word_filter_h
#define _45_word_filter_h

class WordFilter {
public:
    WordFilter(vector<string> words) {
        for (int k = 0; k < words.size(); ++k) {
            for (int i = 0; i <= words[k].size(); ++i) {
                mp[words[k].substr(0, i)].push_back(k);
            }
            for (int i = 0; i <= words[k].size(); ++i) {
                ms[words[k].substr(words[k].size() - i)].push_back(k);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if (!mp.count(prefix) || !ms.count(suffix)) return -1;
        vector<int> pre = mp[prefix], suf = ms[suffix];
        int i = pre.size() - 1, j = suf.size() - 1;
        while (i >= 0 && j >= 0) {
            if (pre[i] < suf[j]) --j;
            else if (pre[i] > suf[j]) --i;
            else return pre[i];
        }
        return -1;
    }
    
private:
    unordered_map<string, vector<int>> mp, ms;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */

#endif /* _45_word_filter_h */
