//
//  602_who_has_most_friend.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _02_who_has_most_friend_h
#define _02_who_has_most_friend_h

select ids as id, cnt as num
from
(
 select ids, count(*) as cnt
 from
 (
  select requester_id as ids from request_accepted
  union all
  select accepter_id from request_accepted
  ) as tbl1
 group by ids
 ) as tbl2
order by cnt desc
limit 1
;

#endif /* _02_who_has_most_friend_h */
