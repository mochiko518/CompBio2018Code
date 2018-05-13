#include <stdio.h>

int main(void){
  int i,j;
  int a[10],b[10];
  int temp;

  for(i=0;i<10;i++){
    a[i]=i;
  }

for(i=0;i<10;i++){
  b[i]=0;
  for(j=0;j<10;j++){
    if(j<=i){
      temp=b[i]+a[j];
  b[i]=temp;
    }
  }
}
for(i=0;i<10;i++){
  printf("%d, %d\n",a[i],b[i]);
}
return 0;
}
