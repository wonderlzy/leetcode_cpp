//
//  627_swap_salary.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _27_swap_salary_h
#define _27_swap_salary_h

UPDATE salary
SET
sex = CASE sex
WHEN 'm' THEN 'f'
ELSE 'm'
END;

#endif /* _27_swap_salary_h */
