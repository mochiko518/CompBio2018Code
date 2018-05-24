#include <stdio.h>

int main(void){

  FILE *fp;

  int ret;

  char name1[100],name2[100];
  int no;
  double value;

  fp=fopen("6-1.csv","r");

  fscanf(fp,"%[^,], %s", name1,name2);
  printf("%s, %s\n",name1,name2);

  while((ret=fscanf(fp,"%d, %lf",&no, &value))!=EOF){
    printf("%d, %f\n",no, value);
  }
  fclose(fp);

  return 0;
}
