//
//  614_second_degree_flower.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _14_second_degree_flower_h
#define _14_second_degree_flower_h

SELECT f1.follower, COUNT(DISTINCT f2.follower) AS num
FROM follow f1
JOIN follow f2 ON f1.follower = f2.followee
GROUP BY f1.follower

#endif /* _14_second_degree_flower_h */
