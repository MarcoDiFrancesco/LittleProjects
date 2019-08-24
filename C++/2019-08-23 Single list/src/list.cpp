#include "list.h"

void saveData(sData);

sNode *insertFirst(sNode *_node, sData _data)
{
  if (_node == NULL)
  {
    _node = new sNode(_data);
    return _node;
  }
  sNode *node = new sNode(_data);
  node->next = _node;
  return node;
}

sNode *insertLast(sNode *_node, sData _data)
{
  if (_node == NULL)
  {
    return insertFirst(_node, _data);
  }
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
  if (_node == NULL)
  {
    return _node;
  }
  _node = _node->next;
  return _node;
}

sNode *removeLastAndSave(sNode *_node)
{
  if (_node->next == NULL) // One element list
  {
    saveData(_node->data);
    delete _node;
    _node = NULL;
    return _node;
  }
  sNode *node = _node;
  while (node->next->next != NULL)
  {
    node = node->next;
  }
  saveData(node->next->data);
  delete node->next;
  node->next = NULL;
  return _node;
}

sNode *removeLast(sNode *_node)
{
  if (_node == NULL) // Zero elements list
  {
    return _node;
  }
  else if (_node->next == NULL) // One element list
  {
    delete _node;
    _node = NULL;
    return _node;
  }
  // Two or more elements
  sNode *node = _node;
  while (node->next->next != NULL)
  {
    node = node->next;
  }
  delete node->next;
  node->next = NULL;
  return _node;
}

sNode *removeSpecific(sNode *_node, sData _data)
{
  if (_node == NULL)
  {
    return _node;
  }
  sNode *node = _node;
  while (node->next != NULL)
  {
    if (node->next->data.value == _data.value)
    {
      if (node->next->next == NULL)
      { // Last element
        return removeLast(_node);
      }
      // Element in the middle
      // delete node->next;
      node->next = node->next->next;
    }
    else
    {
      node = node->next;
    }
  }
  return _node;
}

// Insert data ordered by value
sNode *insertOrder(sNode *_node, sData _data)
{
  if (_node == NULL) // empty list
  {
    return insertFirst(_node, _data);
  }
  else if (_node->data.value >= _data.value) // Insert in the first element of the list
  {
    return insertFirst(_node, _data);
  }
  // Insert in the middle or end of the list
  sNode *node = _node;
  while (node->next != NULL && node->next->data.value < _data.value)
  {
    node = node->next;
  }
  if (node->next == NULL) // Insert in the last element of the list
  {
    return insertLast(_node, _data);
  }
  // Insert in the inside the list
  sNode *newNode = new sNode(_data);
  newNode->next = node->next;
  node->next = newNode;
  return _node;
}

void print(sNode *_node)
{
  if (_node == NULL)
  {
    return;
  }
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
  sNode *node = _node;
  int size;
  if (node == NULL)
  {
    return 0;
  }
  else
  {
    size = 1;
  }
  while (node->next != NULL)
  {
    ++size;
    node = node->next;
  }
  return size;
}

// Check if the list is empty
bool isEmpty(sNode *_node)
{
  if (_node == NULL)
  {
    return true;
  }
  return false;
}

int random(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

void saveData(sData _data)
{
  ofstream outFile("output.txt", ios::app);
  if (outFile.is_open())
  {
    outFile << "[" << _data.index << "," << _data.value << "]" << endl;
  }
  else
  {
    cout << "Error in opening file";
  }
  outFile.close();
}