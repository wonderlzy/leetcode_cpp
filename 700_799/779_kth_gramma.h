//
//  779_kth_gramma.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _79_kth_gramma_h
#define _79_kth_gramma_h

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        if (K % 2 == 0) return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0;
        else return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1;
    }
};

#endif /* _79_kth_gramma_h */
