#include <iostream>
#include <stdlib.h>
using namespace std;

struct sPerson
{
  char *name;
  char *surname;
  int age = 0;

  // default constructor
  sPerson()
  {
    name = "Jane";
    surname = "Doe";
    age = 18;
  };
  
  // specific constructor
  sPerson(char *n, char *s, int a)
  {
    name = n;
    surname = s;
    age = a;
  }

  ~sPerson()
  {
    // delete []name;
    // delete []surname;
    cout << "Deleted" << endl;
  };

  void print()
  {
    cout << name << " " << surname << " " << age << endl;
  };

  void cmp(sPerson cmpPerson)
  {
    if (name == cmpPerson.name && surname == cmpPerson.surname)
    {
      cout << "The two people are equal" << endl;
    } else {
      cout << "The two people are not equal" << endl;
    }
  };
};
