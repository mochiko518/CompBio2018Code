#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int r,i,M,N;
  srand(time(NULL));
  M=1;
  N=6;

  for(i=0;i<100;i++){
    r=rand()%(N-M+1)+M;
    printf("%d\n",r);
    }
  return 0;
}
