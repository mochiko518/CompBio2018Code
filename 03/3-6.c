#include <stdio.h>
#include <math.h>

int main(void){
    int i;
    double x0,xa,x,xx,a;
    double dt;
    x0=10.0;
    x=x0;
    xa=x0;
    a=1.2;
    dt=0.01;

    FILE *fp;
    fp=fopen("3-5.dat","w");
    fprintf(fp,"%f,%f,%f\n",
    0.0,xa,x);
    for(i=1;i<1000;i++){
      xa=x0*exp(a*dt*i);

      xx=x+dt*a*x;
      x=xx;

      fprintf(fp,"%f,%f,%f\n",dt*i,xa,x);
    }

    fclose(fp);
    return 0;
}
