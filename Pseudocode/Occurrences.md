int occurrences(tree T, int min, int max)
  if(T == nil)
    return 0
  else if(T.value < min)
    occurrences(T->right, min, max)
  else if(T.value > max)
    occurrences(T->left, min, max)
  else
    return 1 + occurrences(T->right, min, max) + occurrences(T->left, min, max)
