#include<stdio.h>

int rule(int cell1,int cell2,int cell3);

int main(void){
  int t,i;
  int cell[100];
  int tempcell[100];

  FILE*fp;
  fp=fopen("CC.csv","w");

  //配列の初期化
  for(i=0;i<100;i++){
    cell[i]=0;
    tempcell[i]=0;
  }

  //初期条件
  cell[50]=1;
  for(i=0;i<100;i++){
    fprintf(fp,"%d",cell[i]);
    if(i!=99){
      fprintf(fp,",");
    }
  }
  fprintf(fp,"\n");

  for(t=1;t<100;t++){
    /*-----状態遷移-----*/
    //境界条件処理その１

tempcell[0]=rule(cell[99],cell[0],cell[1]);
   //メイン
   for(i=1;i<99;i++){

tempcell[i]=rule(cell[i-1],cell[i],cell[i+1]);
  }
  //境界条件処理その２

tempcell[99]=rule(cell[98],cell[99],cell[0]);
  /*-----状態遷移ここまで-----*/

  /*-----情報の更新と出力-----*/
  for(i=0;i<100;i++){
    cell[i]=tempcell[i];
    fprintf(fp,"%d",cell[i]);
    if(i!=99){
      fprintf(fp,",");
    }
}
fprintf(fp,"\n");
/*-----情報の更新と出力ここまで-----*/
}

fclose(fp);
return 0;
}

//ルール
int rule(int cell1,int cell2,int cell3){
  if(cell1==1){
    if(cell2==1){
      if(cell3==1){
        return 0;
      }
      else if(cell3==0){
        return 0;
      }
    }
    else if(cell2==0){
         if(cell3==1){
           return 0;
         }
         else if(cell3==0){
           return 1;
         }
    }
  }

  else if(cell1==0){
       if(cell2==1){
         if(cell3==1){
           return 1;
         }
            if(cell3==0){
              return 1;
            }
          }
            else if(cell2==0){
              if(cell3==1){
              return 1;
            }
            else if(cell3==0){
              return 0;
            }
       }
  }
  return -1;
}
