//
//  180_consecutive_nums.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _80_consecutive_nums_h
#define _80_consecutive_nums_h


# Write your MySQL query statement below
SELECT DISTINCT l1.Num as ConsecutiveNums FROM Logs l1, Logs l2, Logs l3
WHERE l1.Id = l2.Id - 1 AND l2.Id = l3.Id - 1
AND l1.Num = l2.Num AND l2.Num = l3.Num;

#endif /* _80_consecutive_nums_h */
