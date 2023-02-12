/*  
Subscripted subscript example from CHOLMOD SuiteSparse 5.4.0
*/

// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>

#define N 30000

int main(){

int i,j,k, p, q , k1, k2;

int pf, psx, nsrow, psi, Ls[N];

int fjk[2], Ax[N], Ap[N], Ai[N], Lx[N], Fx[N], Map[N], Fi[N], Fp[N];


for(i = 0; i < nsrow; i++)
{
   Map[i] = -1;
} 

for(k = 0; k < nsrow; k++)
{
    Map[Ls[psi + k]] = k;
}

//Loop to parallelize
for(k=k1; k<k2; k++)
{
  for(pf=Fp[k]; pf<Fp[k+1]; pf++)
  {
     fjk[0] = Fx[2*pf];
     fjk[1] = Fx[2*pf+1];
     for(p=Ap[Fi[pf]]; p<Ap[Fi[pf]+1]; p++)
     {
        i = Ai[p];
        if(i>=k && Map[i]>=0)
        {
           q = (Map[i]+psx+(k-k1)*nsrow);
           Lx[2*q] += Ax[2*p]*fjk[0]-Ax[2*p+1]*fjk[1];
           Lx[2*q+1] += Ax[2*p+1]*fjk[0]-Ax[2*p]*fjk[1];
        }
     }
  }
}

 
  
	
   return 0;
}
