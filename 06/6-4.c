#include <stdio.h>

int main(void){
  int i,n;
  double sumt,sumx,sumtt,sumtx;
  char name[100];
  double t[100],x[100];
  double a,b;
  int ret;

  FILE *fp;

  //ファイルからデータを読み込む
  fp=fopen("6-3.csv","r");
  fscanf(fp,"%[^,],%s",name,name);
  i=0;
  while((ret=fscanf(fp,"%lf,%lf",&t[i],&x[i]))!=EOF){
    i++;
  }
  fclose(fp);
  //総和をそれぞれ計算する
  n=i;
  sumt=0;
  sumx=0;
  sumtt=0;
  sumtx=0;
  for(i=0;i<n;i++){
    sumt=sumt+t[i];
    sumx=sumx+x[i];
    sumtt=sumtt+t[i]*t[i];
    sumtx=sumtx+t[i]*x[i];
  }
  //導出した式に従い、パラメーターを推定する
  a=(n*sumtx-sumt*sumx)/(n*sumtt-sumt*sumt);
  b=(sumtt*sumx-sumt*sumtx)/(n*sumtt-sumt*sumt);

  printf("a: %f, b: %f\n",a,b);

  return 0;
}
