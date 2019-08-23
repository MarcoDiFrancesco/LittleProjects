#include "list.h"

sNode *insertFirst(sNode *, sData);
sNode *insertLast(sNode *, sData);
sNode *removeFirst(sNode *);
sNode *removeLast(sNode *);
sNode *removeSpecific(sNode *, sData); // Remove first data found

sNode *insertOrder(sNode *, sData);
sNode *removeAllSpecific(sNode *, sData);
sNode *removeCondition(sNode *);


void print(sNode *);
int size(sNode *);

int main()
{
  sNode *node = new sNode();

  node = insertLast(node, sData(1, 1.0));
  node = insertLast(node, sData(2, 2.0));
  node = insertLast(node, sData(3, 3.0));
  node = insertLast(node, sData(3, 3.0));
  node = insertLast(node, sData(3, 3.0));
  node = insertLast(node, sData(4, 4.0));

  // node = removeFirst(node);
  // node = removeLast(node);
  // node = removeSpecific(node, data);

  print(node);

  node = insertOrder(node, sData(2, 2.5));
//  node = removeAllSpecific(node, sData(3, 3.0));
//  node = removeCondition(node);
  print(node);
  cout << "Number of elements: " << node->size() << endl;
}
