//
//  177_get_nth_highest_salary.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _77_get_nth_highest_salary_h
#define _77_get_nth_highest_salary_h

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N - 1;
RETURN (
        SELECT DISTINCT Salary FROM Employee GROUP BY Salary
        ORDER BY Salary DESC LIMIT 1 OFFSET N
        );
END


CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
RETURN (
        SELECT MAX(Salary) FROM Employee E1
        WHERE N =
        (SELECT COUNT(DISTINCT(E2.Salary)) FROM Employee E2
         WHERE E2.Salary >= E1.Salary)
        );
END

#endif /* _77_get_nth_highest_salary_h */
