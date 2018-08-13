#include <stdio.h>
#include <math.h>

#define N 20
#define NBIT 20
#define MAX_GEN 100

double crate=1.0;/*関数crossで使うためのcrateの定義*/
double mrate=0.01;/*関数mutationで使うためのmrateの定義*/


void main()
{
    int chrom[N][NBIT];
    double x[N],z[N],cprob[N];
    int i,j; int gen;
    double xmax=0.0,zmax=-10.0,global_xmax=0.0,global_zmax=-10.0;

    void init(int [][NBIT]); /* 関数 init の型、引数の型等の宣言 */
    void print0(int [][NBIT]); /* 表示用関数の宣言 */
    void func(int [][NBIT],double *,double *); /* 関数 func の型、引数の型等の宣言 */
    void print1(int [][NBIT], double [N], double [N]); /* 表示用関数の宣言 */
    void roulette(double *,double *); /* 関数 roulette の型、引数の型等の宣言 */
    void printpq(double *,double *); /* 表示用関数の宣言 */
    void select(int [][NBIT],double *); /* 関数 select の型、引数の型等の宣言 */
    void cross(int [][NBIT]); /* 関数 cross の型、引数の型等の宣言 */
    void mutation(int [][NBIT]); /* 関数 mutation の型、引数の型等の宣言 */
    void find_max(double *,double *,double *,double *);

    init(chrom); /* 染色体の初期化 */

    print0(chrom); /* chrom を表示 */

    for(gen=0;gen<MAX_GEN;gen++)
    {
      func(chrom,x,z); /* 関数値を計算し、z に代入して戻る */
      print1(chrom,x,z); /*chrom,x,z の値を表示 */
      find_max(x,z,&xmax,&zmax);
      printf(" xmax=%10.6f, zmax=%10.6f ",xmax,zmax);
      if(zmax>=global_zmax) {global_zmax=zmax;global_xmax=xmax;}
      printf(" gxmax=%10.6f, gzmax=%10.6f\n",global_xmax,global_zmax);
      if(gen==MAX_GEN-1) break;
      roulette(z,cprob); /* ルーレットルール */
      printpq(z,cprob);/* 選択確率、累積確率の表示 */
      select(chrom,cprob); /* 選択 */
      print0(chrom);/*選択された chrom を表示 */
      cross(chrom); /* 交叉 */
      print0(chrom);/* 交叉後の chrom を表示 */
      mutation(chrom); /* 突然変異 */
      print0(chrom); /*突然変異後の chrom を表示 */
    }
  }

void init(int x[][NBIT])
{
    int i,j;
    float rnd(short int); /* float 型の関数 rnd を呼ぶための準備 */
    rnd(9);
    for(i=0;i<N;i++)
 {
    for(j=0;j<NBIT;j++)
    {
        if(rnd(1)<=0.5)
            *(*x+i*NBIT+j)=0;/* x[i][j]=0; と同じ */
        else
            *(*x+i*NBIT+j)=1;/* x[i][j]=1; と同じ */
    }
}
return;
}/* end of init */

void print0(int chrom[][NBIT])
{
       int i,j;
       for(i=0;i<N;i++)
       {
           printf("%3d:",i);
           for(j=0;j<NBIT;j++) printf("%1d",chrom[i][j]);
           printf("\n");
        }
        printf("\n");
        return;
}/* end of print0 */

float rnd(short int x)
{
    static short int ix=1 , init_on=0 ;
    if ( ( ( x % 2 )!=0) && (init_on==0) )
        { ix=x ; init_on=1; }
    ix=899*ix ; if( ix<0) ix=ix+32767+1;
    return( ( float )ix/32768.0 );
}/* end of rnd */
void func(int chrom[][NBIT],double *x,double *z)
{
    int i,j,dec,dec_max,dec_p;
    double x_min=0.0, x_max=3.0 , x0 ;
    double f_x(double);
    dec_p=1 ; dec_max=1 ;
    for(i=1;i<NBIT;i++)
    {
        dec_p*=2 ; dec_max+=dec_p;
     }
     for(i=0;i<N;i++)
     {
       dec=chrom[i][0];dec_p=1;
       for(j=1;j<NBIT;j++)
       {
         dec_p*=2 ; dec+=chrom[i][j]*dec_p ;
       }
       x0=x_min+(x_max-x_min)*(double)dec/(double)dec_max;
       *x++=x0 ; *z++=f_x(x0);
     }
return;
}/* end of function */

double f_x(double x)
{
  double pi,y;
  pi=4.0*atan(1.0) ;
  y=2.0+sin(2.2*pi*x)+cos(3.1*pi*x);
  return(y);
}/* end of f_x */

void print1(int chrom[][NBIT],double x[N],double z[N])
{
  int i,j;
  for(i=0;i<N;i++)
  {
    printf("%3d:",i);
    for(j=0;j<NBIT;j++) printf("%1d",chrom[i][j]) ;
    printf(" %10.6f %10.6f",x[i],z[i]) ;
    printf("\n");
  }
  printf("\n");
  return;
}/* end of print1 */

void roulette(double *val, double *q)
{
  int i;
  double sum;
  sum=0.0;
  for(i=0;i<N;i++)
  {
    sum+=*(val+i) ;
  }

*val/=sum ; *q=*val ;
for(i=1;i<N;i++)
{
  *(val+i)/=sum ; *(q+i)=*(q+i-1)+*(val+i) ;
}
return;
}/* end of roulette */

void printpq(double *sp, double *cp)
{
  int i;
  printf(" p_i q_i\n");
  for(i=0;i<N;i++)
{
  printf("%3d:",i);
  printf(" %10.6f %10.6f",sp[i],cp[i]) ;
  printf("\n");
}
printf("\n");
return;
}/* end of print1 */

void select(int chrom[][NBIT],double *val)
{
  int newch[N][NBIT], ns[N];
  int i,j,*chng;
  float rnd(short int), rnd0;

for(i=0;i<N;i++)
{
  rnd0=rnd(1) ;
  for(j=0;j<N;j++)
  {
    if(*(val+j)>(double)rnd0)
    {ns[i]=j ; break; }
  }
}

for(i=0;i<N;i++)
for(j=0;j<NBIT;j++)
{
  chng=*chrom+NBIT*ns[i]+j;
  newch[i][j]=*chng;
}
for(i=0;i<N;i++)
for(j=0;j<NBIT;j++)
{
  chng=*chrom+NBIT*i+j;
  *chng=newch[i][j];
}
return;
}/* end of select */

void cross(int chrom[][NBIT])
{
  int newch[N][NBIT], ns[N];
  int i,j,nc=0,cross_point,i1,i2,*chng1,*chng2;
  float rnd(short int);

for(i=0;i<N;i++)
if(rnd(1)<=crate)
{ ns[nc]=i ; nc++ ; }
if(nc%2==1)
{ ns[nc]=(int)(rnd(1)*(float)N) ; nc++ ; }

for(i=0;i<nc/2;i++)
{
  i1=2*i ; i2=i1+1 ;
  printf("chromosomal crossover target%3d,%3d\n",ns[i1],ns[i2]);
  cross_point=(int)(rnd(1)*(float)(NBIT-1))+1;
  printf("crossing position=%3d\n",cross_point);

for(j=0;j<cross_point;j++)
{
  chng1=*chrom+NBIT*ns[i1]+j;
  chng2=*chrom+NBIT*ns[i2]+j;
  newch[i1][j]=*chng1;
  newch[i2][j]=*chng2;
}
for(j=cross_point;j<NBIT;j++)
{
  chng1=*chrom+NBIT*ns[i1]+j;
  chng2=*chrom+NBIT*ns[i2]+j;
  newch[i1][j]=*chng2;
  newch[i2][j]=*chng1;
}
}

for(i=0;i<nc;i++)
for(j=0;j<NBIT;j++)
{
  chng1=*chrom+NBIT*ns[i]+j;
  *chng1=newch[i][j];
}
printf("\n");
return;
}/* end of cross */

void mutation(int x[][NBIT])
{
  int i,j,*adr_x;
  float rnd(short int);

  for(i=0;i<N;i++)
  {
    for(j=0;j<NBIT;j++)
    {
      if(rnd(1)<=mrate)
      {
        adr_x=*x+NBIT*i+j;
        printf("mutation position is (%3d-th chrom,%3d-th locus)\n",i,j);
        if(*adr_x==1)
        *adr_x=0 ;
        else
        *adr_x=1 ;
      }
    }
  }
  printf("\n");
  return;
}/* end of mutation */

void find_max(double *x,double *z,double *xmax,double *zmax)
{
  int i;
  *zmax=-10.0;
  for(i=0;i<N;i++)
  {
    if(*(z+i)>*zmax) { *zmax=*(z+i) ; *xmax=*(x+i) ;}
  }
  return;
}/* end of find_max */
