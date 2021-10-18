/*  Very Simple Parallelizable Loop Example
*/

#include <stdio.h>
#include <math.h>

#define n 10000

int main(){
    
  int a[30000];
  
  int b[30000];

  int c[30000];
  
  for (int i=0 ; i<n; i++) {

   for(int j=0; j<n; j++){
      a[2*n*i+j]= b[i];
      c[i] = a[2*n*i+j+n];
   }

  }

  // for (int i=0 ; i<n; i++) {

  //     a[i]= b[i];
  //     c[i] = a[i+n];

  // }


}
