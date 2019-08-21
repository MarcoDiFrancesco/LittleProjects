#include <iostream>
using namespace std;

struct myStruct
{
  int x;
};

int main()
{
  string x = "0123456789 0123456789 0123456789 0123456789 0123456789 0123456789 0123456789 0123456789 0123456789 0123456789";
  cout << sizeof(x);

  int *a, b;
  a = &b;
  cout << *a << endl; // not known
  *a = 5;
  cout << *a << endl; // 5
  b = 10;
  cout << *a << endl; // 10

  int *const c = &b;
  // c = &a; not permitted because c is constant

  myStruct *myStructPointer, myStructNotPointer;
  myStructPointer = &myStructNotPointer;
  myStructNotPointer.x = 15;
  (*myStructPointer).x += 5;
  cout << myStructNotPointer.x << endl;
  myStructPointer->x += 5;
  cout << myStructNotPointer.x << endl;

  int d[5] = {0, 1, 2, 3, 4};
  cout << &d << " " << &d[0] << " " << &d[1] << endl;
  cout << &d[4] - &d[1];
}