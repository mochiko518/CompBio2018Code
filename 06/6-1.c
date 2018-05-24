#include <stdio.h>

void myprint(int i);

int main(void){
  int i;
  for(i=0;i<10;i++){
    myprint(i);
  }

   return 0;
}

void myprint(int i){
  if(i%2==0){
    printf("even\n");
  }
  else{
    printf("odd\n");
  }
}
