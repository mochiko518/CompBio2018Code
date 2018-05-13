#include <stdio.h>

int main(void){
  int i1,i2;
  double d1,d2;

  i1=5;
  d1=6.0;
  i2=(int)d1%i1;
  d2=(double)i1/d1;

  printf("%d,%f\n",i2,d2);

  return 0;
}
