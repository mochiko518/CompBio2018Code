#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){
  FILE *fp;
  fp=fopen("13-3.csv", "w");

  int i;
  double t, S, I, R, a, b, e[3], ran, ran2;
  a=0.000001;
  b=0.001;
  S=10000;
  I=1;
  R=0;
  t=0;
  fprintf(fp, "%f, %f, %f, %f\n", t, S, I, R);
  srand((unsigned)time(NULL));

  for(i=1; i<=20000; i++){
    e[1]=a*S*I;
    e[2]=b*I;
    e[0]=e[1]+e[2];

    ran=(double)rand()/RAND_MAX;
    while(ran==0||ran==1){
      ran=(double)rand()/RAND_MAX;
    }
    t=t+log(1/ran)/e[0];

    ran2=(double)rand()/RAND_MAX;

    if(0<=ran2&&ran2<=e[1]/e[0]){
      S=S-1;
      I=I+1;
    }
    else{
      I=I-1;
      R=R+1;
    }
    if(I==0){
      break;
    }
    fprintf(fp, "%f, %f, %f, %f\n", t, S, I, R);
  }

  fclose(fp);
  return 0;
}
