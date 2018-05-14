#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int r,M,N,x,i,j;
  double xx;
  xx=0.0;
  srand(time(NULL));
  for(j=0;j<100;j++){
  M=1;
  N=6;
  x=0;
  for(i=0;i<100;i++){
    r=rand()%(N-M+1)+M;
    x=x+r;
    if(x>=100){
      xx+=i;
      //printf("%d\n",i);
      break;
    }
  }
}
printf("%f\n",xx/100);

return 0;
}
