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
 Very Simple Parallelizable Loop Example

*/
int main()
{
int a[30000], b[30000] = {0}, c[30000], d[30000];
	int i, n, j, count, p, x;
	int _ret_val_0;
	n=3000;
	p=1;
	count=3;
	#pragma cetus private(i, j) 
	#pragma loop name main#0 
	for (j=0; j<n; j ++ )
	{
		d[j]=p;
		#pragma cetus private(i) 
		#pragma loop name main#0#0 
		#pragma cetus reduction(+: p) 
		#pragma cetus parallel 
		#pragma omp parallel for private(i) reduction(+: p)
		for (i=0; i<n; i ++ )
		{
			if (c[i]!=0)
			{
				b[i]=i;
				if (x!=0)
				{
					a[i]=c[i];
				}
				p ++ ;
			}
		}
	}
	{
		int j = 0;
		#pragma loop name main#1 
		for (; j<n; j ++ )
		{
			if ((j%2)==0)
			{
				a[j]=0;
			}
			else
			{
				a[j]=1;
			}
		}
	}
	{
		int j = 0;
		#pragma loop name main#2 
		for (; j<n; j ++ )
		{
			a[j]=(a[j-1]+a[j]);
		}
	}
	_ret_val_0=0;
	return _ret_val_0;
}
