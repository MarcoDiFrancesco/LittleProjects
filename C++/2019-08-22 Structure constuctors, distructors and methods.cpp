#include <iostream>
#include <stdlib.h>
using namespace std;

struct sDate
{
  int day = 1;
  int month = 1;
  int year = 1970;
  sDate(int d, int m, int y)
  {
    day = d;
    month = m;
    year = y;
  }
  sDate(int d, int m)
  {
    day = d;
    month = m;
  }
  sDate(int d)
  {
    day = d;
  }
  sDate()
  {
    day = 1;
    month = 1;
    year = 1970;
  }
  void print(){
    cout << year << "-" << month << "-" << day << endl;
  }
  // destructor method
  ~sDate(){
    cout << "date deleted" << endl;
  }
  int cmp(sDate sDate);
};

int main()
{
  // declaration using structure 1 (day, month and year)
  sDate dateDMY = sDate(22, 8, 2019);
  dateDMY.print();
  dateDMY.day += 1;
  dateDMY.month += 1;
  dateDMY.year += 1;

  // declaration using structure 2 (day and month)
  sDate dateDM = sDate(22, 8);
  dateDM.print();

  // declaration using structure 3 (day)
  sDate dateD = sDate(22);
  dateD.print();

  // testing default copy costructor
  sDate newDate = dateDMY;
  newDate.print();
}