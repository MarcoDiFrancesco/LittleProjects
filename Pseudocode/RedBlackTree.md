struct Tree {
  color
  right
  left
  parent
}

boolear isRedBlack(Tree T)
  if(T->parent == FLASE)
    if(T == BLACK)
      return TRUE
    else
      return FALSE
  else if(T->left == FALSE && T->right == FALSE)
    if(T == RED)
      return FALSE
    if(blackHeight(T->left) != blackHeight(T->right))
    
    if(isRedBlack(T->left) == TRUE or isRedBlack(T->right) == TRUE)
      return TRUE
    else
      return FALSE
  if(T == RED)
    if(isRedBlack(T->left) == TRUE && isRedBlack(T->right) == TRUE)
      return TRUE
    else
      return FALSE

int blackHeight(T)
  if(T->parent == FALSE)
    return 1 + height
  else
    return 1 + height + blackHeight(T)