#include "person.h"

int main() {
  sPerson anna = sPerson("Anna","Rossi",1970);
  sPerson mario = sPerson("Mario","Rossi",1980);
  anna.print();
  mario.print();
  sPerson marioCopy = mario;
  marioCopy.cmp(mario);
  
}
