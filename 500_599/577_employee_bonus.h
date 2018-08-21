//
//  577_employee_bonus.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _77_employee_bonus_h
#define _77_employee_bonus_h

SELECT
    Employee.name, Bonus.bonus
FROM
    Employee
        LEFT OUTER JOIN
    Bonus ON Employee.empid = Bonus.empid
;

#endif /* _77_employee_bonus_h */
