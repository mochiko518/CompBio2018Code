#include <stdio.h>

int main(void){
  int i;

  for(i=0;i<100;i++){
    printf("%d\n",i);
    if(i==10){
      break;

    }
  }
  return 0;
}
