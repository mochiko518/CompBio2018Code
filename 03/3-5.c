#include <stdio.h>

int main(void){
  int i,t;
  double r,x,xx,K;
  K=100;

  FILE *fp;
  fp=fopen("output.dat","w");

  for(i=150;i<300;i++){
    r=(double)i/100;
    x=10;
    for(t=0;t<1000;t++){
      xx=x+r*(1-x/K)*x;
      x=xx;
      if(t>900){
        fprintf(fp,"%f, %f\n",r,x);
      }
    }
  }
  fclose(fp);
  return 0;
}
