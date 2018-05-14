#include <stdio.h>
#include <stdlib.h>

int main(void){
  int r,i;
  srand(1);

  for(i=0;i<100;i++){
    r=rand();
    printf("%d\n",r);
  }
  return 0;

}
