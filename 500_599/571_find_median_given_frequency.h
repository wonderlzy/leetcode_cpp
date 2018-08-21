//
//  571_find_median_given_frequency.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _71_find_median_given_frequency_h
#define _71_find_median_given_frequency_h

select FORMAT(avg(n.Number),4)*1.0 as median
from Numbers n left join
(
 select Number, @prev := @count as prevNumber, (@count := @count + Frequency) as countNumber
 from Numbers,
 (select @count := 0, @prev := 0, @total := (select sum(Frequency) from Numbers)) temp order by Number
 ) n2
on n.Number = n2.Number
where
(prevNumber < floor((@total+1)/2) and countNumber >= floor((@total+1)/2))
or
(prevNumber < floor((@total+2)/2) and countNumber >= floor((@total+2)/2))

#endif /* _71_find_median_given_frequency_h */
