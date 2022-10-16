/*  
Subscripted subscript example from CHOLMOD SuiteSparse 5.4.0
*/

// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>

#define N 30000

int main(){

int i,j,k, p, q , k1, k2;

int pf, psx, nsrow, psi,pdi1,px;

int Ax[N], Ap[N], Ai[N], Lx[N], Fx[N], Map[N], RelativeMap[N],Ls[N],C[N];

int ndrow1 = 81, ndrow2=30, nsrow = 399;

for(i = 0; i < nsrow; i++)
{
   Map[i] = -1;
} 

for(k = 0; k < nsrow; k++)
{
    Map[Ls[psi + k]] = k;
}


for (i = 0 ; i < ndrow2 ; i++)
{
    RelativeMap [i] = Map [Ls [pdi1 + i]] ;
}

//Loop to parallelize
    for (j = 0 ; j < ndrow1 ; j++)              /* cols k1:k2-1 */
    {   
        px = psx + RelativeMap [j] * nsrow ;
        for (i = j ; i < ndrow2 ; i++)          /* rows k1:n-1 */
        {
                    
            q = px + RelativeMap [i] ;
            Lx [2*q] -= C [2*(i+ndrow2*j)] ;
            Lx [2*q+1] -= C [2*(i+ndrow2*j)+1] ;
        }
    
    }

 
  
	
   return 0;
}
