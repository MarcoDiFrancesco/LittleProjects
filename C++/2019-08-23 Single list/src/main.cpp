#include "list.h"

sNode *insertFirst(sNode *, sData);
sNode *insertLast(sNode *, sData);
sNode *removeFirst(sNode *);
sNode *removeLast(sNode *);
sNode *removeSpecific(sNode *, sData);

void print(sNode *);
int size(sNode *);

int main()
{
  sNode *node = new sNode();
  
  sData data1 = sData(2, 2.0);
  node = insertFirst(node, data1);
  
  sData data2 = sData(3, 3.0);
  node = insertLast(node, data2);

  sData data3 = sData(4, 4.0);
  node = insertFirst(node, data3);
  
  node = removeFirst(node);
  print(node);

  node = removeLast(node);
  print(node);
  
  node = removeSpecific(node, data3);
  print(node);

  cout << "Number of elements: " << node->size() << endl;
}
