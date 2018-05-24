#include <stdio.h>

int main(void){

  FILE *fp;
  int ret;

  int i,j;
  char name1[100],name2[100];
  int no[100],notemp;
  double value[100],valuetemp;

  //データを読み込む
  fp=fopen("6-1.csv","r");
fscanf(fp,"%[^,], %s", name1,name2);

i=0;
while((ret=fscanf(fp,"%d, %lf" ,&notemp,&valuetemp))!=EOF){
  no[i]=notemp;
  value[i]=valuetemp;
  i++; //データを何列読み込んだかカウント
}
fclose(fp);
//データを書き込む
fp=fopen("6-2.csv","w");
for(j=0;j<i;j++){
  fprintf(fp,"%d,%f\n",no[j],value[j]);
}
fclose(fp);

return 0;
}
