#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(X,Y)(((X) > (Y))?(X) :(Y))
#define MAX_Weight 1000
#define MAX_Num 4

int Cost[MAX_Num] = {400,150,150,120};
int Weight[MAX_Num] = {850,300,500,200};

int C[MAX_Num+1][MAX_Weight+1];



void knapsack(int n,int w){

    memset(C,0,sizeof(C));
  //  printf("memset!\n");
    int i,j;
    for(i = 0; i < n; i++)
      for(j = 0; j < w; j++){
          printf("(%d,%d) \n",i,j);
          if(j - Weight[i] < 0){
             C[i+1][j] = C[i][j];
           }
           else  C[i+1][j] = MAX(C[i][j],C[i][j-Weight[i]]+Cost[i]);
      }
}



int main(){

  knapsack(MAX_Num+1,MAX_Weight+1);
  printf("finished!\n");
  printf("Max Value: %d \n",C[MAX_Num-1][MAX_Weight]);


  return 0;
}
