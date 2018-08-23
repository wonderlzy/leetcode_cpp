//
//  710_blacklist_random.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _10_blacklist_random_h
#define _10_blacklist_random_h

class Solution {
private:
    int upperBound;
    vector<int> blackCnt;
    
public:
    Solution(int N, vector<int> blacklist) : upperBound(N), blackCnt(blacklist)  {
        upperBound -= (int)blackCnt.size();
        sort(blackCnt.begin(), blackCnt.end());
        for(int i = 1; i < blackCnt.size(); ++i)
            blackCnt[i] -= i;
    }
    
    int pick() {
        int num = rand() % upperBound;
        int sta = 0, end = blackCnt.size();
        while(sta < end) {
            int mid = sta + (end - sta) / 2;
            if(blackCnt[mid] <= num)
                sta = mid + 1;
            else
                end = mid;
        }
        return num + sta;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */

#endif /* _10_blacklist_random_h */
