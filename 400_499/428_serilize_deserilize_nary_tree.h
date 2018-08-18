//
//  428_serilize_deserilize_nary_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/18.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _28_serilize_deserilize_nary_tree_h
#define _28_serilize_deserilize_nary_tree_h


// This function stores the given N-ary tree in a file pointed by fp
void serialize(Node *root, FILE *fp)
{
    // Base case
    if (root == NULL) return;
    
    // Else, store current node and recur for its children
    fprintf(fp, "%c ", root->key);
    for (int i = 0; i < N && root->child[i]; i++)
        serialize(root->child[i],  fp);
    
    // Store marker at the end of children
    fprintf(fp, "%c ", MARKER);
}

// This function constructs N-ary tree from a file pointed by 'fp'.
// This functionr returns 0 to indicate that the next item is a valid
// tree key. Else returns 0
int deSerialize(Node *&root, FILE *fp)
{
    // Read next item from file. If theere are no more items or next
    // item is marker, then return 1 to indicate same
    char val;
    if ( !fscanf(fp, "%c ", &val) || val == MARKER )
        return 1;
    
    // Else create node with this item and recur for children
    root = newNode(val);
    for (int i = 0; i < N; i++)
        if (deSerialize(root->child[i], fp))
            break;
    
    // Finally return 0 for successful finish
    return 0;
}

#endif /* _28_serilize_deserilize_nary_tree_h */
