//
//  579_find_cumulative_salary.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _79_find_cumulative_salary_h
#define _79_find_cumulative_salary_h

SELECT
E1.id,
E1.month,
(IFNULL(E1.salary, 0) + IFNULL(E2.salary, 0) + IFNULL(E3.salary, 0)) AS Salary
FROM
(SELECT
 id, MAX(month) AS month
 FROM
 Employee
 GROUP BY id
 HAVING COUNT(*) > 1) AS maxmonth
LEFT JOIN
Employee E1 ON (maxmonth.id = E1.id
                AND maxmonth.month > E1.month)
LEFT JOIN
Employee E2 ON (E2.id = E1.id
                AND E2.month = E1.month - 1)
LEFT JOIN
Employee E3 ON (E3.id = E1.id
                AND E3.month = E1.month - 2)
ORDER BY id ASC , month DESC
;


#endif /* _79_find_cumulative_salary_h */
