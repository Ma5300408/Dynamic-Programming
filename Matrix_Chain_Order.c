#include<stdio.h>
#include<stdlib.h>

#define SIZE 7

int p[SIZE] = {30, 35, 15, 5, 10, 20, 25};
int m[SIZE][SIZE];
int s[SIZE-1][SIZE];


void Matrix_Chain_Order(int * p){

  int n = SIZE-1;
  int i;
  for(i = 1; i <= n; i++)m[i][i] = 0;
  
  int l;
  for(l = 2; l <= n; l++){
      for(i = 1; i <= n-l+1; i++){
         int j = i+l-1;
         m[i][j] = 1e9;
         int k;
         for(k = i; k <= j-1; k++){
          int  q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
            if(q < m[i][j]){
              m[i][j] = q;
              s[i][j] = k;
            }
         }
      }
  } 

  return;
}




int main()
{
  Matrix_Chain_Order(p);
  
  int i,j;
  for(i = 0; i < SIZE; i++){
    for(j = 0; j < SIZE; j++){
     printf("%d ",m[i][j]);
    }
    printf("\n");
  }


  for(i = 1; i < SIZE-1; i++){
    for(j = 2; j < SIZE; j++){
      printf("%d ",s[i][j]);
    }
    printf("\n");
  }



  return 0;
}
