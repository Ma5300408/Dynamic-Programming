#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define X_Len 7
#define Y_Len 6

char X[X_Len+1] = "ABCBDAB";
char Y[Y_Len+1] = "BDCABA";
int Cost_Table[X_Len+1][Y_Len+1];
int X_Y_Table[X_Len+1][Y_Len+1];
const int Left_Up = 1;
const int Up = 2;
const int Left = 3;


void LCS(char * X,char * Y){


    int i,j,k;
    for(i = 1; i <= X_Len; i++)Cost_Table[i][0] = 0;
    for(j = 0; j <= Y_Len; j++)Cost_Table[0][j] = 0;

     for(i = 1; i < X_Len+1; i++)
       for(j = 1; j < Y_Len+1; j++){
        //     printf("before strcmp!\n");       
             
          if( X[i-1] == Y[j-1] ){
               Cost_Table[i][j] = Cost_Table[i-1][j-1] + 1;
               X_Y_Table[i][j] = Left_Up; 
               
           }
          else if(Cost_Table[i-1][j] >= Cost_Table[i][j-1]){
                  Cost_Table[i][j] = Cost_Table[i-1][j];
                  X_Y_Table[i][j] = Up;
          }

         else{
                Cost_Table[i][j] = Cost_Table[i][j-1];
                X_Y_Table[i][j] = Left;
             }
        
        // printf("After strcmp!\n");

      }

   return;
}



void print_LCS(int * Table,char * Array,int i,int j){
    
   if(i == 0 || j == 0)return;

   if(Table[i*(Y_Len+1)+j] == 1){
      print_LCS(Table,Array,i-1,j-1);
      printf("%c",Array[i-1]);
      }
   else if(Table[i*(Y_Len+1)+j] == 2)print_LCS(Table,Array,i-1,j);
   else print_LCS(Table,Array,i,j-1);


}





int main()
{

   LCS(X,Y);
   //printf("LCS finished!\n");
   int i,j;
   for(i = 0; i <= X_Len; i++){
     for(j = 0; j <= Y_Len; j++){
        printf(" %d ",Cost_Table[i][j]);
     }
     printf("\n");
   }

   
    for(i = 1; i <= X_Len; i++){
     for(j = 1; j <= Y_Len; j++){
       if(X_Y_Table[i][j]==1) printf(" X ");
       else if(X_Y_Table[i][j]==2)printf(" ^ ");
       else if(X_Y_Table[i][j]==3)printf(" < ");
       else printf(" ");
     }
     printf("\n");
   }
    printf("\n\n");
   print_LCS((int*)X_Y_Table,X,X_Len,Y_Len);
    printf("\n");

  return 0;
}
