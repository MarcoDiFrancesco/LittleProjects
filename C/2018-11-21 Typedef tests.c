#include <stdio.h>
#include <stdlib.h>

struct StructureName {
  int field1;
  int field2;
} variable1, variable2;

typedef struct { // anonymous struct
  int field1;
  int field2;
} NameType;

struct {
  int m;
  int q;
} r1, r2;

typedef struct Retta {
  int n1;
  int n2;
} Retta;

int main(){
  variable1.field1 = 11;
  
  r1.m = 1;
  printf("%d",r1.m);
 
}