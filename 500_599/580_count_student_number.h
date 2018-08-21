//
//  580_count_student_number.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _80_count_student_number_h
#define _80_count_student_number_h

SELECT
dept_name, COUNT(student_id) AS student_number
FROM
department
LEFT OUTER JOIN
student ON department.dept_id = student.dept_id
GROUP BY department.dept_name
ORDER BY student_number DESC , department.dept_name
;

#endif /* _80_count_student_number_h */
