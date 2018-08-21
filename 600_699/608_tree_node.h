//
//  608_tree_node.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _08_tree_node_h
#define _08_tree_node_h

SELECT
atree.id,
IF(ISNULL(atree.p_id),
   'Root',
   IF(atree.id IN (SELECT p_id FROM tree), 'Inner','Leaf')) Type
FROM
tree atree
ORDER BY atree.id

#endif /* _08_tree_node_h */
