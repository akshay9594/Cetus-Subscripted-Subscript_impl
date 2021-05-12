/*  Very Simple Parallelizable Loop Example
*/

int main(){

  int a[30000] ,b[30000] = {0}, c[30000], d[30000];
  
  int i , n,  j , count , p ,x;

   n = 3000;
   p = 1;
   count = 3;


for(j = 0; j < n; j++){

   for(i = 0; i < n; i++){

      if(c[i] != 0){

         b[i] = i;
         if(x != 0){
            a[i] = c[i];
         }
         p++;
      }
   }

   d[j] = p; 
   
}

  


// for( i = 0 ; i < n; i++){
//    a[i] = i + 1;
// }


for(int j=0 ; j < n; j++) {

     if(j%2 ==0)
       a[j] = 0;
      else
       a[j] = 1;
     
  }

  for(int j=0 ; j<n; j++) {

     a[j] = a[j-1] + a[j];
     
  }
 
  
	
   return 0;
}
