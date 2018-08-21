//
//  620_note_boring_film.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _20_note_boring_film_h
#define _20_note_boring_film_h

select *
from cinema
where mod(id, 2) = 1 and description != 'boring'
order by rating DESC
;

#endif /* _20_note_boring_film_h */
