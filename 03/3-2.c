#include <stdio.h>

int main(void){
  int i;
  for(i=0;i<10;i++){
    printf("%d: ",i);
    if(i>5){
      printf("i is greater than 5,");
    }
    if(i==3){
      printf("i=3,");
        }
        if((i>=3)&&(i<=6)){
          printf("i is 3 or more and 6 or less,");
      }
      if(!(i==1||i==2)){
        printf("i is not 1 or2,");
      }
      printf("\n");
  }
  return 0;
}
