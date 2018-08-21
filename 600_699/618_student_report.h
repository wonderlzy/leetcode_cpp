//
//  618_student_report.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _18_student_report_h
#define _18_student_report_h

SELECT
America, Asia, Europe
FROM
(SELECT @as:=0, @am:=0, @eu:=0) t,
(SELECT
 @as:=@as + 1 AS asid, name AS Asia
 FROM
 student
 WHERE
 continent = 'Asia'
 ORDER BY Asia) AS t1
RIGHT JOIN
(SELECT
 @am:=@am + 1 AS amid, name AS America
 FROM
 student
 WHERE
 continent = 'America'
 ORDER BY America) AS t2 ON asid = amid
LEFT JOIN
(SELECT
 @eu:=@eu + 1 AS euid, name AS Europe
 FROM
 student
 WHERE
 continent = 'Europe'
 ORDER BY Europe) AS t3 ON amid = euid
;

#endif /* _18_student_report_h */
