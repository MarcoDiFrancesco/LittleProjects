#include <iostream>
using namespace std;
typedef char PersonalizedString[100];

struct PersonalizedStruct {
  int structInt;
  bool structBool;
};

struct {
  int anonymInt;
  bool anonymBool;
} myAnonymStruct;

int randomNumber(int,int);
char randomCharacter();

int main() {
  PersonalizedStruct structOne;
  myAnonymStruct.anonymInt = 3;
  structOne.structInt = 1;
  cout << structOne.structInt << endl;
  cout << myAnonymStruct.anonymInt << endl;
  
  cout << randomNumber(0,5);
  cout << randomCharacter();

}

int randomNumber(int min, int max) {
  int random;
  random = rand()%(max-min+1)+min;
  
  return random;
}

char randomCharacter() {
  char character;
  character = rand()%('Z'-'A'-1)+'A';
  return character;
}