#include "list.h"

sNode *insertFirst(sNode *_node, sData _data)
{
  sNode *node = new sNode();
  node->data = _data;
  node->next = _node;
  return node;
}

sNode *insertLast(sNode *_node, sData _data)
{
  // Pointer to scan the list
  sNode *node = _node;
  while (node->next != NULL)
  {
    node = node->next;
  }
  node->next = new sNode(_data);
  return _node;
}

sNode *removeFirst(sNode *_node)
{
  sNode *newNode = new sNode();
  newNode = _node;
  _node = _node->next;
  delete (newNode);
  return _node;
}

sNode *removeLast(sNode *_node)
{
  sNode *node = _node;
  if (node == NULL) // zero elements list
  {
    return node;
  }
  else if (node->next == NULL) // one element list
  {
    delete (node);
    _node = NULL; // or: return NULL;
  }
  else
  { // two or more elements
    while (node->next->next != NULL)
    {
      node = node->next;
    }
    delete node->next;
    node->next = NULL;
  }
  return _node;
}

sNode *removeSpecific(sNode *_node, sData _data)
{
  sNode *node = _node;
  if (node == NULL)
  {
    return _node;
  }
  while (node->next != NULL)
  {
    if (node->next->data.value == _data.value && node->next->next != NULL)
    {
      // Found equal data
      sNode *tempNode = node->next;
      delete tempNode;
      return _node;
    }
    else if (node->next->data.value == _data.value && node->next->next == NULL)
    {
      // Last element of the list
      return removeLast(_node);
    }
    node = node->next;
  }
  return removeFirst(_node);
}

// Insert data ordered by value
sNode *insertOrder(sNode *_node, sData _data)
{
  sNode *node = _node;
  sNode *newNode = new sNode(_data);
  if (node == NULL) // empty list
  {
    node = newNode;
    delete newNode;
    delete node;
  }
  else
  {
    while (node->next->next != NULL)
    {
      if (node->next->data.value > newNode->data.value)
      {
        // Found smaller value
        newNode->next = node->next;
        node->next = newNode;
        return _node;
      }
      node = node->next;
    }
  }
  delete newNode;
  delete node;
  return _node;
}

sNode *removeAllSpecific(sNode *_node, sData _data)
{
  sNode *node = _node;

  return _node;
}

sNode *removeCondition(sNode *_node, sData _data)
{
  sNode *node = _node;

  return _node;
}

void print(sNode *_node)
{
  sNode *node = _node;
  while (node != NULL)
  {
    node->print();
    node = node->next;
  }
  cout << endl;
}

// TBD
int size(sNode *_node)
{

  return 0;
}
