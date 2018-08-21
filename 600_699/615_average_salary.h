//
//  615_average_salary.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _15_average_salary_h
#define _15_average_salary_h

select department_salary.pay_month, department_id,
case
when department_avg>company_avg then 'higher'
when department_avg<company_avg then 'lower'
else 'same'
end as comparison
from
(
 select department_id, avg(amount) as department_avg, date_format(pay_date, '%Y-%m') as pay_month
 from salary join employee on salary.employee_id = employee.employee_id
 group by department_id, pay_month
 ) as department_salary
join
(
 select avg(amount) as company_avg,  date_format(pay_date, '%Y-%m') as pay_month from salary group by date_format(pay_date, '%Y-%m')
 ) as company_salary
on department_salary.pay_month = company_salary.pay_month
;

#endif /* _15_average_salary_h */
