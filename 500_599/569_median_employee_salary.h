//
//  569_median_employee_salary.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _69_median_employee_salary_h
#define _69_median_employee_salary_h

SELECT
Employee.Id, Employee.Company, Employee.Salary
FROM
Employee,
Employee alias
WHERE
Employee.Company = alias.Company
GROUP BY Employee.Company , Employee.Salary
HAVING SUM(CASE
           WHEN Employee.Salary = alias.Salary THEN 1
           ELSE 0
           END) >= ABS(SUM(SIGN(Employee.Salary - alias.Salary)))
ORDER BY Employee.Id
;

#endif /* _69_median_employee_salary_h */
