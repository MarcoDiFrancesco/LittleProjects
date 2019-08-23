#ifndef __LIST__
#define __LIST__

#include <iostream>
#include <stdlib.h>
using namespace std;

struct sData
{
  int index;
  float value;

  // Default constructor
  sData()
  {
    index = 0;
    value = 0;
  }

  // Specific constructor
  sData(int _index, float _value)
  {
    index = _index;
    value = _value;
  }

  // Destructor
  ~sData()
  {
  }

  void print() const
  {
    cout << index << "-" << value << "\t";
  }

  // Less than function: Compares if the values inside this node is smaller than the value of the given value
  bool lt(sData _data)
  {
    if (value < _data.value)
    {
      return true;
    }
    return false;
  }

  // Greater than function: Compares if the values inside this node is bigger than the value of the given value
  bool gt(sData _data)
  {
    if (value > _data.value)
    {
      return true;
    }
    return false;
  }
};

// Link of the last node is NULL
struct sNode
{
  sData data;
  sNode *next;

  // Default constructor
  sNode()
  {
    data = sData();
    next = NULL;
  }

  sNode(sData _data)
  {
    data = _data;
    next = NULL;
  }

  sNode(sData _data, sNode *_next)
  {
    data = _data;
    next = _next;
  }

  // Node deletion
  ~sNode()
  {
  }

  void print() const
  {
    data.print();
  }

  // Return the quantity of nodes inside the list
  int size() const
  {
    return 0;
  }
};

#endif
