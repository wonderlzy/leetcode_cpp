//
//  825_num_friends_requests.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _25_num_friends_requests_h
#define _25_num_friends_requests_h

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int a[121] = {}, res = 0;
        for (auto age : ages) ++a[age];
        for (auto i = 15, minAge = 15, sSum = 0; i <= 120; sSum += a[i], res += a[i++] * (sSum - 1))
            while (minAge <= 0.5 * i + 7) sSum -= a[minAge++];
        return res;
    }
};

#endif /* _25_num_friends_requests_h */
