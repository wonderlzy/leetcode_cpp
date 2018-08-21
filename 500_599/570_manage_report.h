//
//  570_manage_report.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _70_manage_report_h
#define _70_manage_report_h

SELECT
Name
FROM
Employee AS t1 JOIN
(SELECT
 ManagerId
 FROM
 Employee
 GROUP BY ManagerId
 HAVING COUNT(ManagerId) >= 5) AS t2
ON t1.Id = t2.ManagerId
;

#endif /* _70_manage_report_h */
