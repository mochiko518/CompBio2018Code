#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
int i,j;
int a[10][10];
srand(time(NULL));
for(i=0;i<10;i++){
for(j=0;j<10;j++){
a[i][j]=rand()%10;
}
}
for(i=0;i<10;i++){
for(j=0;j<10;j++){
printf("%d",a[i][j]);
if(j!=9){
printf(", ");
}
}
printf("¥n");
}
return 0;
}
