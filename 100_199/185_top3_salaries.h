//
//  185_top3_salaries.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _85_top3_salaries_h
#define _85_top3_salaries_h

SELECT d.Name AS Department, e.Name AS Employee, e.Salary FROM Employee e
JOIN Department d on e.DepartmentId = d.Id
WHERE (SELECT COUNT(DISTINCT Salary) FROM Employee WHERE Salary > e.Salary
       AND DepartmentId = d.Id) < 3 ORDER BY d.Name, e.Salary DESC;


SELECT d.Name AS Department, e.Name AS Employee, e.Salary FROM
(SELECT e1.Name, e1.Salary, e1.DepartmentId FROM Employee e1 JOIN Employee e2
 ON e1.DepartmentId = e2.DepartmentId AND e1.Salary <= e2.Salary GROUP BY e1.Id
 HAVING COUNT(DISTINCT e2.Salary) <= 3) e JOIN Department d ON e.DepartmentId = d.Id
ORDER BY d.Name, e.Salary DESC;

SELECT d.Name AS Department, e.Name AS Employee, e.Salary FROM Employee e, Department d
WHERE (SELECT COUNT(DISTINCT Salary) FROM Employee WHERE Salary > e.Salary
       AND DepartmentId = d.Id) IN (0, 1, 2) AND e.DepartmentId = d.Id ORDER BY d.Name, e.Salary DESC;

#endif /* _85_top3_salaries_h */
