#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 50

int main (void){
  int a[N],aa[N],i,t,r1,r2,r,k,m,aaa,SUM,mm;

  double ave;
  k=10;
  SUM=0;
  mm=100;
  srand(time(NULL));

  for(m=0;m<100;m++){
    for(i=0;i<k;i++){
      a[i]=1;
    }
    for(i=k;i<N;i++){
      a[i]=0;
}

for(t=0;t<518000;t++){
  aaa=0;

      for(i=0;i<N;i++){
        r1=rand()%N;
        r2=rand()%N;
        r=rand()%2;
        if(r==0){
aa[i]=a[r1];
        }
        if(r==1){
          aa[i]=a[r2];
        }
aaa=aaa+aa[i];
      }
      if(aaa==50){
        SUM=SUM+t;
        break;
      }
      for(i=0;i<N;i++){
        a[i]=aa[i];
      }
    }
    if(aaa!=50){
      mm=mm-1;
    }
  }
  ave=(double)SUM/((double)mm+1);
  printf("%f\n",ave);
  return 0;
}
