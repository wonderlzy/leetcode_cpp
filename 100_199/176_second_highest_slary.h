//
//  176_second_highest_slary.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _76_second_highest_slary_h
#define _76_second_highest_slary_h

SELECT Salary FROM Employee GROUP BY Salary
UNION ALL (SELECT NULL AS Salary)
ORDER BY Salary DESC LIMIT 1 OFFSET 1;

SELECT MAX(Salary) FROM Employee
WHERE Salary NOT IN
(SELECT MAX(Salary) FROM Employee);

SELECT MAX(Salary) FROM Employee
Where Salary <
(SELECT MAX(Salary) FROM Employee);

#endif /* _76_second_highest_slary_h */
