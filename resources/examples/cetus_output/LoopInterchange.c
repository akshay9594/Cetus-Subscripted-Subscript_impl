/*
Copyright (C) 1991-2020 Free Software Foundation, Inc.
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


Different loops to test the Loop Interchange pass in Cetus.


*/
int a[10000][10000], c[10000], b[10000][10000], d[10000][10000];
int work[10000][10000][10000], coef2[1000][10000], coef4[10000][10000];
int S[10000], x[10000][10000], y[10000][10000], f[10000][10000], e[10000][10000];
int main()
{
	int i, j, k, n, r, jmi, ld1, ld2, ldi, ld, m;
	int _ret_val_0;
	n=10000;
	r=1000;
	/* n = 10000; */
	/* r = 1000; */
	#pragma loop name main#0 
	#pragma cetus private(i, j) 
	for (i=0; i<10000; i ++ )
	{
		#pragma loop name main#0#0 
		#pragma cetus private(j) 
		#pragma cetus parallel 
		#pragma omp parallel for private(j)
		for (j=0; j<10000; j ++ )
		{
			b[j][i]=(2*b[j+1][i-1]);
		}
	}
	/* Taken from ARC2D (Perfect Benchmarks) */
	#pragma loop name main#1 
	#pragma cetus private(j, k) 
	#pragma cetus parallel 
	#pragma omp parallel for private(j, k)
	for (j=0; j<10000; j ++ )
	{
		#pragma loop name main#1#0 
		#pragma cetus private(k) 
		#pragma cetus parallel 
		#pragma omp parallel for private(k)
		for (k=0; k<10000; k ++ )
		{
			work[j][k][3]=((coef2[j][k]*work[j][k][1])-(coef4[j][k]*work[j][k][2]));
		}
	}
	/* From ARC2D Perfect benchmarks */
	#pragma loop name main#2 
	#pragma cetus private(j, k, ld, ld1, ld2, ldi) 
	for (j=0; j<n; j ++ )
	{
		#pragma loop name main#2#0 
		#pragma cetus private(k, ld, ld1, ld2, ldi) 
		#pragma cetus parallel 
		#pragma omp parallel for if((10000<(1L+(9L*n)))) private(k, ld, ld1, ld2, ldi)
		for (k=0; k<n; k ++ )
		{
			ld2=a[j][k];
			ld1=(b[j][k]-(ld2*x[j-2][k]));
			ld=(d[j][k]-((ld2*y[j-2][k])+(ld1*x[j-2][k])));
			ldi=(1.0/ld);
			f[j][k]=(((f[j][k]-(ld2*f[j-2][k]))-(ld1*f[j-1][k]))*ldi);
			x[j][k]=((d[j][k]-(ld1*y[j-1][k]))*ld1);
			y[j][k]=(e[j][k]*ldi);
		}
	}
	/* Matrix Multiplication kernel */
	#pragma loop name main#3 
	#pragma cetus private(i, j, k) 
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<(((1L+(3L*n))+((3L*n)*n))+(((3L*m)*n)*n)))) private(i, j, k)
	for (i=0; i<n; i ++ )
	{
		#pragma loop name main#3#0 
		#pragma cetus private(j, k) 
		for (k=0; k<n; k ++ )
		{
			#pragma loop name main#3#0#0 
			#pragma cetus reduction(+: d[i][j]) 
			#pragma cetus private(j) 
			#pragma cetus parallel 
			#pragma omp parallel for if((10000<(1L+(3L*m)))) private(j) reduction(+: d[i][j])
			for (j=0; j<m; j ++ )
			{
				d[i][j]=(d[i][j]+(a[i][k]*b[k][j]));
			}
		}
	}
	#pragma loop name main#4 
	#pragma cetus private(i, j) 
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<((1L+(3L*n))+((3L*n)*n)))) private(i, j)
	for (j=0; j<n; j ++ )
	{
		#pragma loop name main#4#0 
		#pragma cetus private(i) 
		#pragma cetus parallel 
		#pragma omp parallel for if((10000<(1L+(3L*n)))) private(i)
		for (i=0; i<n; i ++ )
		{
			a[j][i]=(0.2*((((b[j][i]+b[j-1][i])+b[j][i-1])+b[j+1][i])+b[j][i+1]));
		}
	}
	_ret_val_0=0;
	return _ret_val_0;
}
