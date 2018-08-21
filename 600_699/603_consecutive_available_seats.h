//
//  604_consecutive_available_seats.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _04_consecutive_available_seats_h
#define _04_consecutive_available_seats_h

select distinct a.seat_id
from cinema a join cinema b
on abs(a.seat_id - b.seat_id) = 1
and a.free = true and b.free = true
order by a.seat_id
;

#endif /* _04_consecutive_available_seats_h */
