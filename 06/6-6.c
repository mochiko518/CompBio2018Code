#include<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	<math.h>

int main(void){
  double beta,gamma,S,SS,I,II,R,RR,t,dt,x1,x2,y1,y2,I2,N;
  int i;

  S=0.99;
  I=0.01;
  R=0.0;
  beta=1.0;
  gamma=0.3;
  t=0.0;
  dt=0.001;

  FILE *fp;

  fp=fopen("6-6.csv","w");

for(i=0;t<100;i++){
  SS=S+dt*(-beta*S*I);
  II=I+dt*(beta*S*I-gamma*I);
  RR=R+dt*(gamma*I);

  S=SS;
  I=II;
  R=RR;


    x1=(((double)rand()+1)	/	((double)RAND_MAX	+	1))	*	N;
    x2=(((double)rand()+1)	/	((double)RAND_MAX	+	1))	*	N;
    y1=sqrt(-2*log(x1))*cos(2*M_PI*x2);
    y2=sqrt(-2*log(x1))*sin(2*M_PI*x2);

    I2=I+y1;

  if(i%1000==0){
    fprintf(fp,"%f,%f,%f,%f\n",t,S,I2,R);
  }
  t+=dt;
}

fclose(fp);
return 0;
}
