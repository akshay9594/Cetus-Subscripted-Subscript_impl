/*  Very Simple Parallelizable Loop Example
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 30000

int main(){

  int a[N] , b[N], c[N], d[N];
  int Ax[N] = {0} , s[N] = {0};
  
  int i , n , p , x;
  int j,k;
   p = 1;
   n = 30000;

   for(i = 0 ; i < n; i++){
      b[i] = 0;
   }

   for(j = 0; j < n; j++){

      d[j] = p;
      for(i = 0; i < n; i++){

         if(c[i] != 0){

            b[i] = i;
            if(x != 0){
               a[i] = c[i];
            }
            p++;
         }
      }

      
   }


   for(j=0; j < n; j++){

      for(k =d[j]; k < d[j+1]; k++){

         Ax[k] = Ax[k] * s[j];

      }

   }

for(j=0 ; j < n; j++) {

     if(j%2 ==0)
       a[j] = 0;
      else
       a[j] = 1;
     
  }

  for(j=0 ; j<n; j++) {

     a[j] = a[j-1] + a[j];
     
  }
 
  
	
   return 0;
}
