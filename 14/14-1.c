#include <stdio.h>

int main(void){
  int i,j,k;
  double t,dt;
  double x[3];
  double xx[3];
  double a,b,c,d,e,f,g;

  FILE *fp;
  fp=fopen("output_14-1.csv","w");

  dt=0.0001;
  a=0.75;
  b=2.0;
  c=0.2;
  d=0.01;
  e=3.0;
  f=0.5;
  g=0.0001;

  t=0.0;
  x[0]=1000;
  x[1]=250;
  x[2]=100000;
  fprintf(fp,"%f, %f, %f, %f\n",t,x[0],x[1],x[2]);
  for(i=1;i<=100000;i++){
    t=dt*i;
    xx[0]=x[0]+dt*(-a*x[1])*x[0];
    xx[1]=x[1]+dt*(b-c*x[0]-d*x[1])*x[1];
    xx[2]=x[2]+dt*(e-f*x[0]-g*x[2])*x[2];
    x[0]=xx[0];
    x[1]=xx[1];
    x[2]=xx[2];

    if(i%100==0){
      fprintf(fp,"%f, %f, %f, %f\n",t,x[0],x[1],x[2]);
    }
  }
  fclose(fp);
  return 0;
}
