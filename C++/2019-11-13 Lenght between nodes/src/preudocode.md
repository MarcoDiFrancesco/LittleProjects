# Pseudocode
checkLenght(start, lenght, graph)
  if(node == end)
    save lenght
  else if(node not visited)
    node.visited = true
    lenght++
    for(i:all connected nodes)
      checkLenght(i, lenght, graph)
