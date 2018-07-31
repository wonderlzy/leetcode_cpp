//
//  178_rank_scores.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _78_rank_scores_h
#define _78_rank_scores_h

SELECT Score,
(SELECT COUNT(DISTINCT Score) FROM Scores WHERE Score >= s.Score) Rank
FROM Scores s ORDER BY Score DESC;

SELECT Score,
(SELECT COUNT(*) FROM (SELECT DISTINCT Score s FROM Scores) t WHERE s >= Score) Rank
FROM Scores ORDER BY Score DESC;


#endif /* _78_rank_scores_h */
