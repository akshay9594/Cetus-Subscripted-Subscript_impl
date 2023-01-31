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
 
Subscripted subscript example from EVSL (Eigen Value Solver)

*/
/* #include <stdio.h> */
/* #include <math.h> */
/* #include <stdlib.h> */
int main()
{
	int i, j, msteps, width, sigma2, numPlaced, npts = 30000;
	double t, ritzVal[30000];
	int y[30000], ind[30000], xdos[30000], gamma2[30000];
	int _ret_val_0;
	numPlaced=0;
	#pragma cetus private(j) 
	#pragma loop name main#0 
	for (j=0; j<npts; j ++ )
	{
		if ((xdos[j]-t)<width)
		{
			ind[numPlaced ++ ]=j;
		}
	}
	/* Loop to parallelize */
	#pragma cetus private(j) 
	#pragma loop name main#1 
	/* #pragma cetus reduction(+: y[ind[j]])  */
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<(1L+(103L*numPlaced)))) private(j)
	for (j=0; j<numPlaced; j ++ )
	{
		y[ind[j]]+=(gamma2[i]*exp(( - ((xdos[ind[j]]-t)*(xdos[ind[j]]-t)))/sigma2));
	}
	_ret_val_0=0;
	return _ret_val_0;
}
