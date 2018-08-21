//
//  597_friend_requests.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _97_friend_requests_h
#define _97_friend_requests_h

select
round(
      ifnull(
             (select count(*) from (select distinct requester_id, accepter_id from request_accepted) as A)
             /
             (select count(*) from (select distinct sender_id, send_to_id from friend_request) as B),
             0)
      , 2) as accept_rate;

#endif /* _97_friend_requests_h */
