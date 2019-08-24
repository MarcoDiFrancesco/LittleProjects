#include "list.h"

// Not ordered list functions
sNode *insertFirst(sNode *, sData);
sNode *insertLast(sNode *, sData);
sNode *removeFirst(sNode *);
sNode *removeLast(sNode *);
sNode *removeLastAndSave(sNode *);
sNode *removeSpecific(sNode *, sData);
sNode *insertOrder(sNode *, sData); // Insert data in order by sData.value

void print(sNode *);
int size(sNode *);
bool isEmpty(sNode *);
int random(int, int);

int main()
{
  /*
  sNode *node = new sNode();

  node = insertLast(node, sData(1, 1.0));
  node = insertLast(node, sData(2, 2.0));
  node = insertLast(node, sData(3, 3.0));
  node = insertLast(node, sData(4, 3.0));
  node = insertLast(node, sData(5, 3.0));
  node = insertLast(node, sData(6, 4.0));
  print(node);
  
  node = removeSpecific(node, sData(3, 3.0));
  print(node);
  node = insertOrder(node, sData(7,3.0));
  print(node);
  
  cout << size(node) << endl;
  */

  sNode *arrayList[3];
  arrayList[0] = NULL;
  arrayList[1] = NULL;
  arrayList[2] = NULL;

  // Add random elements
  for (int i = 0; i < 20; i++)
  {
    int nList = random(0, 2);
    sData *data = new sData(i, random(0, 10));
    arrayList[nList] = insertOrder(arrayList[nList], *data);
  }

  print(arrayList[0]);
  print(arrayList[1]);
  print(arrayList[2]);

  while (arrayList[0] != NULL || arrayList[1] != NULL || arrayList[2] != NULL)
  {
    if (size(arrayList[0]) >= size(arrayList[1]) && size(arrayList[0]) >= size(arrayList[2]))
    {
      cout << "Remove from arrayList[0]" << endl;
      arrayList[0] = removeLastAndSave(arrayList[0]);
    }
    else if (size(arrayList[1]) >= size(arrayList[2]))
    {
      cout << "Remove from arrayList[1]" << endl;
      arrayList[1] = removeLastAndSave(arrayList[1]);
    }
    else
    {
      cout << "Remove from arrayList[2]" << endl;
      arrayList[2] = removeLastAndSave(arrayList[2]);
    }
    print(arrayList[0]);
    print(arrayList[1]);
    print(arrayList[2]);
  }
}
