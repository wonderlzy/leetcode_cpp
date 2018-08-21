//
//  596_cant_more_5students.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _96_cant_more_5students_h
#define _96_cant_more_5students_h

select class from courses group by class having count(distinct student) >= 5


#endif /* _96_cant_more_5students_h */
