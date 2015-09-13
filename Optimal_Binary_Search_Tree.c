#include<stdio.h>
#include<stdlib.h>

#define SIZE 5


double p[SIZE+1] = {0 , 0.15 , 0.1 , 0.05 , 0.1 , 0.2};
double q[SIZE+1] = {0.05 , 0.1 ,  0.05 , 0.05 , 0.05 , 0.1};
double e[SIZE+2][SIZE+1];
double w[SIZE+2][SIZE+1];
int root[SIZE+1][SIZE+1];

void OBST(double * p,double * q,int size)
{
     int i;
     for(i = 1; i <= size+2; i++){
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
     }
     int l;
     for(l = 1; l <= size+1; l++)
         for(i = 1; i <= size+1-l+1; i++){
          int j = i+l-1;
           e[i][j] = 1e9;
           w[i][j] = w[i][j-1] + p[j] + q[j];
           int r;
           for(r = i; r<=j; r++){
             double  t = e[i][r-1] + e[r+1][j] + w[i][j];
               if(t < e[i][j]){
                  e[i][j] = t;
                  root[i][j] = r;

               }
           }

         }


   return;   
}


int main(){

   
  OBST(p,q,SIZE-1);
  int i,j;
  for(i = 1; i <= SIZE+2; i++){
       for(j = 0; j < SIZE+1; j++){
        printf(" %.4f ",e[i][j]);
       }
    printf("\n");
  }

  for(i = 0; i < SIZE+1; i++){
     for(j = 0; j < SIZE+1; j++){
       printf(" %d ",root[i][j]);
     }
    printf("\n");
  }
   

  return 0;
}
