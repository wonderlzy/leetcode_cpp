//
//  181_earn_more_than_boss.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _81_earn_more_than_boss_h
#define _81_earn_more_than_boss_h

# Write your MySQL query statement below
SELECT e1.Name as Employee FROM Employee e1
JOIN Employee e2 ON e1.ManagerId = e2.Id
WHERE e1.Salary > e2.Salary;

#endif /* _81_earn_more_than_boss_h */
