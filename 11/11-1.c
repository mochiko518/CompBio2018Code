#include <stdio.h>

int main(){
  int i,j;
  int t;
  double dt=0.01;
  double u[100][100];
  double utemp[100][100];

  double D=0.4;

  FILE *fp;

  fp=fopen("11-1.csv","w");

  //初期化
  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      u[i][j]=0;
    }
  }

  u[49][49]=1;
  u[49][50]=1;
  u[50][49]=1;
  u[50][50]=1;

  //初期値出力
  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      fprintf(fp,"%f",u[i][j]);
      if(j!=99){
  fprintf(fp,",");
      }
    }
    fprintf(fp,"\n");
  }

  for(t=1;t<5000;t++){

    //境界条件
     //i=0,j=0
    i=0;
    j=0;
    utemp[i][j]=u[i][j]+dt*(D*(u[99][j]+u[i+1][j]+u[i][99]+u[i][j+1]-4*u[i][j]));
    //i=0,j=99

    i=0;
    j=99;
    utemp[i][j]=u[i][j]+dt*(D*(u[99][j]+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i][j]));
    //i=99,j=0

    i=99;
    j=0;
    utemp[i][j]=u[i][j]+dt*(D*(u[i-1][j]+u[0][j]+u[i][99]+u[i][j+1]-4*u[i][j]));
    //i=99,j=99
    i=99;
    j=99;
    utemp[i][j]=u[i][j]+dt*(D*(u[i-1][j]+u[0][j]+u[i][j-1]+u[i][0]-4*u[i][j]));

    //i=0
    i=0;
    for(j=1;j<99;j++){
      utemp[i][j]=u[i][j]+dt*(D*(u[99][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i][j]));
    }
    //i=99
    i=99;
    for(j=1;j<99;j++){
      utemp[i][j]=u[i][j]+dt*(D*(u[i-1][j]+u[0][j]+u[i][j-1]+u[i][j+1]-4*u[i][j]));
    }
    //j=0
    j=0;
    for(i=1;i<99;i++){
      utemp[i][j]=u[i][j]+dt*(D*(u[i-1][j]+u[i+1][j]+u[i][99]+u[i][j+1]-4*u[i][j]));
    }
    //j=99
    j=99;
    for(i=1;i<99;i++){
      utemp[i][j]=u[i][j]+dt*(D*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i][j]));
    }

  //その他
  for(i=1;i<99;i++){
    for(j=1;j<99;j++){
      utemp[i][j]=u[i][j]+dt*(D*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i][j]));
    }
  }
//更新
for(i=0;i<100;i++){
  for(j=0;j<100;j++){
    u[i][j]=utemp[i][j];
  }
}

//出力
if(t%500==0){
  for(i=0;i<100;i++){
    for(j=0;j<100;i++){
      fprintf(fp,"%f",u[i][j]);
      if(j!=99){
        fprintf(fp,",");
      }
    }
    fprintf(fp,"\n");
  }
}
}
fclose(fp);
return 0;
}
