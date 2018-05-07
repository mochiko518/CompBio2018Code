#include <stdio.h>
#include <math.h>

int main(void){
    int i;
    double x0,xa,x,xx,r,k;
    double dt;
    x0=10.0;
    x=x0;
    xa=x0;
    r=1.2;
    k=100;
    dt=0.1;

    FILE *fp;
    fp=fopen("3-5.dat","w");
    fprintf(fp,"%f,%f,%f\n",
    0.0,xa,x);
    for(i=1;i<100;i++){
      xa=k/(1+(-1+k/x0)*exp(-r*dt*i));

      xx=x+dt*r*(1-x/k)*x;
      x=xx;

      fprintf(fp,"%f,%f,%f\n",dt*i,xa,x);
    }

    fclose(fp);
    return 0;
}
