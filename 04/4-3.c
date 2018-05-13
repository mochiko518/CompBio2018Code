#include  <stdio.h>

int main(void){
  int i,j;

  for(i=0;i<10;i++){
    j=0;
    while (j<i){
      printf("True, ");
      j++;
    }
    printf("\n");
  }
  return 0;
}
