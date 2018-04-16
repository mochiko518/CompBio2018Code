#include <stdio.h>

int main(void){
  FILE *fp;
  fp=fopen("hello.dat", "w");

  fprintf(fp, "Hello, World!");

  fclose(fp);
  return 0;
}
