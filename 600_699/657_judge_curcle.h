//
//  657_judge_curcle.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _57_judge_curcle_h
#define _57_judge_curcle_h

class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt1 = 0, cnt2 = 0;
        for (char move : moves) {
            if (move == 'U') ++cnt1;
            else if (move == 'D') --cnt1;
            else if (move == 'L') ++cnt2;
            else if (move == 'R') --cnt2;
        }
        return cnt1 == 0 && cnt2 == 0;
    }
};

#endif /* _57_judge_curcle_h */
