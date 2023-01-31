/*
Copyright (C) 1991-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it andor
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https:www.gnu.org/licenses/>. 
*/
/*
This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it. 
*/
/*
glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default. 
*/
/*
wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISOIEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters
*/
/*
 
Subscripted subscript example from CHOLMOD SuiteSparse 5.4.0

*/
/* #include <stdio.h> */
/* #include <math.h> */
/* #include <stdlib.h> */
int main()
{
	int i, j, k, p, q, k1, k2;
	int pf, psx, nsrow, psi, Ls[30000];
	int fjk[2], Ax[30000], Ap[30000], Ai[30000], Lx[30000], Fx[30000], Map[30000], Fi[30000], Fp[30000];
	int _ret_val_0;
	int k_0;
	int pf_0;
	int p_0;
	#pragma cetus private(i) 
	#pragma loop name main#0 
	#pragma cetus parallel 
	#pragma omp parallel for private(i)
	for (i=0; i<30000; i ++ )
	{
		Map[i]=( - 1);
	}
	#pragma cetus private(k) 
	#pragma loop name main#1 
	for (k=0; k<30000; k ++ )
	{
		Map[Ls[psi+k]]=k;
	}
	/* Loop to parallelize */
	/* Normalized Loop */
	#pragma cetus private(fjk, i, p, p_0, pf, pf_0, q) 
	#pragma cetus lastprivate(k_0) 
	#pragma loop name main#2 
	/* #pragma cetus reduction(+: Lx[((2q)+1)], Lx[(2*q)])  */
	#pragma cetus parallel 
	#pragma omp parallel for private(fjk, i, p, p_0, pf, pf_0, q) lastprivate(k_0)
	for (k_0=0; k_0<=((-1+(-1*k1))+k2); k_0 ++ )
	{
		/* Normalized Loop */
		#pragma cetus private(fjk, i, p, p_0, q) 
		#pragma cetus lastprivate(pf_0) 
		#pragma loop name main#2#0 
		/* #pragma cetus reduction(+: Lx[((2q)+1)], Lx[(2*q)])  */
		for (pf_0=0; pf_0<=((-1+Fp[(1+k1)+k_0])+(-1*Fp[k1+k_0])); pf_0 ++ )
		{
			fjk[0]=Fx[2*(pf_0+Fp[k1+k_0])];
			fjk[1]=Fx[(2*(pf_0+Fp[k1+k_0]))+1];
			/* Normalized Loop */
			#pragma cetus private(i, q) 
			#pragma cetus lastprivate(p_0) 
			#pragma loop name main#2#0#0 
			/* #pragma cetus reduction(+: Lx[((2q)+1)], Lx[(2*q)])  */
			for (p_0=0; p_0<=((-1+Ap[1+Fi[pf_0+Fp[k1+k_0]]])+(-1*Ap[Fi[pf_0+Fp[k1+k_0]]])); p_0 ++ )
			{
				i=Ai[p_0+Ap[Fi[pf_0+Fp[k1+k_0]]]];
				if ((i>=(k1+k_0))&&(Map[i]>=0))
				{
					q=((Map[i]+psx)+(((k1+k_0)-k1)*30000));
					Lx[2*q]+=((Ax[2*(p_0+Ap[Fi[pf_0+Fp[k1+k_0]]])]*fjk[0])-(Ax[(2*(p_0+Ap[Fi[pf_0+Fp[k1+k_0]]]))+1]*fjk[1]));
					Lx[(2*q)+1]+=((Ax[(2*(p_0+Ap[Fi[pf_0+Fp[k1+k_0]]]))+1]*fjk[0])-(Ax[2*(p_0+Ap[Fi[pf_0+Fp[k1+k_0]]])]*fjk[1]));
				}
			}
			p=(p_0+Ap[Fi[pf_0+Fp[k1+k_0]]]);
		}
		pf=(pf_0+Fp[k1+k_0]);
	}
	k=(k1+k_0);
	_ret_val_0=0;
	return _ret_val_0;
}
