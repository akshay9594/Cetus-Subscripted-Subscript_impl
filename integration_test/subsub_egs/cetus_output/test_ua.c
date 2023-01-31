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
 
  Example loop from the UA benchmark in the NAS
  Parallel Benchmarks (NPB 3.3)

*/
/*
Define ISO C stdio on top of C++ iostreams.
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

	ISO C99 Standard: 7.19 Input/output	<stdio.h>

*/
/*
Handle feature test macros at the start of a header.
   Copyright (C) 2016-2021 Free Software Foundation, Inc.
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
This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included. 
*/
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
These are defined by the user (or the compiler)
   to specify the desired environment:

   __STRICT_ANSI__	ISO Standard C.
   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
   _ISOC11_SOURCE	Extensions to ISO C99 from ISO C11.
   _ISOC2X_SOURCE	Extensions to ISO C99 from ISO C2X.
   __STDC_WANT_LIB_EXT2__
			Extensions to ISO C99 from TR 27431-2:2010.
   __STDC_WANT_IEC_60559_BFP_EXT__
			Extensions to ISO C11 from TS 18661-1:2014.
   __STDC_WANT_IEC_60559_FUNCS_EXT__
			Extensions to ISO C11 from TS 18661-4:2015.
   __STDC_WANT_IEC_60559_TYPES_EXT__
			Extensions to ISO C11 from TS 18661-3:2015.
   __STDC_WANT_IEC_60559_EXT__
			ISO C2X interfaces defined only in Annex F.

   _POSIX_SOURCE	IEEE Std 1003.1.
   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
			if >=199309L, add IEEE Std 1003.1b-1993;
			if >=199506L, add IEEE Std 1003.1c-1995;
			if >=200112L, all of IEEE 1003.1-2004
			if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
			Single Unix conformance is wanted, to 600 for the
			sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and XOpen Unix extensions.
   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N	Select default filesystem interface.
   _ATFILE_SOURCE	Additional *at interfaces.
   _DYNAMIC_STACK_SIZE_SOURCE Select correct (but non compile-time constant)
			MINSIGSTKSZ, SIGSTKSZ and PTHREAD_STACK_MIN.
   _GNU_SOURCE		All of the above, plus GNU extensions.
   _DEFAULT_SOURCE	The default set of features (taking precedence over
			__STRICT_ANSI__).

   _FORTIFY_SOURCE	Add security hardening to many library functions.
			Set to 1 or 2; 2 performs stricter checks than 1.

   _REENTRANT, _THREAD_SAFE
			Obsolete; equivalent to _POSIX_C_SOURCE=199506L.

   The `-ansi' switch to the GNU C compiler, and standards conformance
   options such as `-std=c99', define __STRICT_ANSI__.  If none of
   these are defined, or if _DEFAULT_SOURCE is defined, the default is
   to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200809L, as well as enabling miscellaneous functions from BSD and
   SVID.  If more than one of these are defined, they accumulate.  For
   example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE together
   give you ISO C, 1003.1, and 1003.2, but nothing else.

   These are defined by this file and are used by the
   header files to decide what to declare or define:

   __GLIBC_USE (F)	Define things from feature set F.  This is defined
			to 1 or 0; the subsequent macros are either defined
			or undefined, and those tests should be moved to
			__GLIBC_USE.
   __USE_ISOC11		Define ISO C11 things.
   __USE_ISOC99		Define ISO C99 things.
   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
   __USE_ISOCXX11	Define ISO C++11 things.
   __USE_POSIX		Define IEEE Std 1003.1 things.
   __USE_POSIX2		Define IEEE Std 1003.2 things.
   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
   __USE_XOPEN		Define XPG things.
   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
   __USE_UNIX98		Define Single Unix V2 things.
   __USE_XOPEN2K        Define XPG6 things.
   __USE_XOPEN2KXSI     Define XPG6 XSI things.
   __USE_XOPEN2K8       Define XPG7 things.
   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
   __USE_LARGEFILE	Define correct standard I/O things.
   __USE_LARGEFILE64	Define LFS things with separate names.
   __USE_FILE_OFFSET64	Define 64bit interface as default.
   __USE_MISC		Define things from 4.3BSD or System V Unix.
   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
   __USE_DYNAMIC_STACK_SIZE Define correct (but non compile-time constant)
			MINSIGSTKSZ, SIGSTKSZ and PTHREAD_STACK_MIN.
   __USE_GNU		Define GNU extensions.
   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.

   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
   only for compatibility.  All new code should use the other symbols
   to test for features.

   All macros listed above as possibly being defined by this file are
   explicitly undefined if they are not explicitly defined.
   Feature-test macros that are not defined by the user or compiler
   but are implied by the other feature-test macros defined (or by the
   lack of any definitions) are defined by the file.

   ISO C feature test macros depend on the definition of the macro
   when an affected header is included, not when the first system
   header is included, and so they are handled in
   <bits/libc-header-start.h>, which does not have a multiple include
   guard.  Feature test macros that can be handled from the first
   system header included are handled here. 
*/
/* Undefine everything, so we get a clean slate.  */
/*
Suppress kernel-name space pollution unless user expressedly asks
   for it. 
*/
/*
Convenience macro to test the version of gcc.
   Use like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note: only works for GCC 2.0 and later, because __GNUC_MINOR__ was
   added in 2.0. 
*/
/*
Similarly for clang.  Features added to GCC after version 4.2 may
   or may not also be available in clang, and clang's definitions of
   __GNUC(_MINOR)__ are fixed at 4 and 2 respectively.  Not all such
   features can be queried via __has_extension__has_feature. 
*/
/* Whether to use feature set F.  */
/*
_BSD_SOURCE and _SVID_SOURCE are deprecated aliases for
   _DEFAULT_SOURCE.  If _DEFAULT_SOURCE is present we do not
   issue a warning; the expectation is that the source is being
   transitioned to use the new macro. 
*/
/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */
/*
If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined,
   define _DEFAULT_SOURCE. 
*/
/* This is to enable the ISO C2X extension.  */
/* This is to enable the ISO C11 extension.  */
/* This is to enable the ISO C99 extension.  */
/* This is to enable the ISO C90 Amendment 1:1995 extension.  */
/*
If none of the ANSIPOSIX macros are defined, or if _DEFAULT_SOURCE
   is defined, use POSIX.1-2008 (or another version depending on
   _XOPEN_SOURCE). 
*/
/*
Some C libraries once required _REENTRANT andor _THREAD_SAFE to be
   defined in all multithreaded code.  GNU libc has not required this
   for many years.  We now treat them as compatibility synonyms for
   _POSIX_C_SOURCE=199506L, which is the earliest level of POSIX with
   comprehensive support for multithreaded code.  Using them never
   lowers the selected level of POSIX conformance, only raises it. 
*/
/*
Features part to handle 64-bit time_t support.
   Copyright (C) 2021 Free Software Foundation, Inc.
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
/* We need to know the word size in order to check the time size.  */
/* Determine the wordsize from the preprocessor defines.  */
/* Both x86-64 and x32 use the 64-bit system call interface.  */
/*
Bit size of the time_t type at glibc build time, x86-64 and x32 case.
   Copyright (C) 2018-2021 Free Software Foundation, Inc.
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
/* For others, time size is word size.  */
/*
The function 'gets' existed in C89, but is impossible to use
   safely.  It has been removed from ISO C11 and ISO C++14.  Note: for
   compatibility with various implementations of <cstdio>, this test
   must consider only the value of __cplusplus when compiling C++. 
*/
/*
GNU formerly extended the scanf functions with modified format
   specifiers %as, %aS, and %a[...] that allocate a buffer for the
   input using malloc.  This extension conflicts with ISO C99, which
   defines %a as a standalone format specifier that reads a floating-
   point number; moreover, POSIX.1-2008 provides the same feature
   using the modifier letter 'm' instead (%ms, %mS, %m[...]).

   We now follow C99 unless GNU extensions are active and the compiler
   is specifically in C89 or C++98 mode (strict or not).  For
   instance, with GCC, -std=gnu11 will have C99-compliant scanf with
   or without -D_GNU_SOURCE, but -std=c89 -D_GNU_SOURCE will have the
   old extension. 
*/
/*
Get definitions of __STDC_ predefined macros, if the compiler has
   not preincluded this header automatically. 
*/
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
This macro indicates that the installed library is the GNU C Library.
   For historic reasons the value now is 6 and this will stay from now
   on.  The use of this variable is deprecated.  Use __GLIBC__ and
   __GLIBC_MINOR__ now (see below) when you want to test for a specific
   GNU C library version and use the values in <gnulib-names.h> to get
   the sonames of the shared libraries. 
*/
/*
Major and minor version number of the GNU C library package.  Use
   these macros to test for features in specific releases. 
*/
/* This is here only because every header file already includes this one.  */
/*
Copyright (C) 1992-2021 Free Software Foundation, Inc.
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
/* We are almost always included from features.h. */
/*
The GNU libc does not support any K&R compilers or the traditional mode
   of ISO C compilers anymore.  Check for some of the combinations not
   supported anymore. 
*/
/* Some user header file might have defined this before.  */
/*
Compilers that lack __has_attribute may object to
       #if defined __has_attribute && __has_attribute (...)
   even though they do not need to evaluate the right-hand side of the &&.
   Similarly for __has_builtin, etc. 
*/
/*
All functions, except those with callbacks or those that
   synchronize memory, are leaf functions. 
*/
/*
GCC can always grok prototypes.  For C++ programs we add throw()
   to help it optimize the function calls.  But this only works with
   gcc 2.8.x and egcs.  For gcc 3.4 and up we even mark C functions
   as non-throwing using a function attribute since programs can use
   the -fexceptions options for C code as well. 
*/
/*
These two macros are not used in glibc anymore.  They are kept here
   only because some other projects expect the macros to be defined. 
*/
/*
For these things, GCC behaves the ANSI way normally,
   and the non-ANSI way under -traditional. 
*/
/* This is not a typedef so `const __ptr_t' does the right thing.  */
/* C++ needs to know that types and declarations are C, not C++.  */
/* Fortify support.  */
/* Use __builtin_dynamic_object_size at _FORTIFY_SOURCE=3 when available.  */
/*
Support for flexible arrays.
   Headers that should use flexible arrays only if they're "real"
   (e.g. only if they won't affect sizeof()) should test
   #if __glibc_c99_flexarr_available. 
*/
/*
__asm__ ("xyz") is used throughout the headers to rename functions
   at the assembly language level.  This is wrapped by the __REDIRECT
   macro, in order to support compilers that can do this some other
   way.  When compilers don't support asm-names at all, we have to do
   preprocessor tricks instead (which don't have exactly the right
   semantics, but it's the best we can do).

   Example:
   int __REDIRECT(setpgrp, (__pid_t pid, __pid_t pgrp), setpgid);
*/
/*

#elif __SOME_OTHER_COMPILER__

# define __REDIRECT(name, proto, alias) name proto; 	_Pragma("let " #name " = " #alias)
)

*/
/*
GCC and clang have various useful declarations that can be made with
   the '__attribute__' syntax.  All of the ways we use this do fine if
   they are omitted for compilers that don't understand it. 
*/
/*
At some point during the gcc 2.96 development the `malloc' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings. 
*/
/*
Tell the compiler which arguments to an allocation function
   indicate the size of the allocation. 
*/
/*
At some point during the gcc 2.96 development the `pure' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings. 
*/
/* This declaration tells the compiler that the value is constant.  */
/*
At some point during the gcc 3.1 development the `used' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings. 
*/
/* Since version 3.2, gcc allows marking deprecated functions.  */
/*
Since version 4.5, gcc also allows one to specify the message printed
   when a deprecated function is used.  clang claims to be gcc 4.2, but
   may also support this feature. 
*/
/*
At some point during the gcc 2.8 development the `format_arg' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.
   If several `format_arg' attributes are given for the same function, in
   gcc-3.0 and older, all but the last one are ignored.  In newer gccs,
   all designated arguments are considered. 
*/
/*
At some point during the gcc 2.97 development the `strfmon' format
   attribute for functions was introduced.  We don't want to use it
   unconditionally (although this would be possible) since it
   generates warnings. 
*/
/*
The nonnull function attribute marks pointer parameters that
   must not be NULL. 
*/
/*
The returns_nonnull function attribute marks the return type of the function
   as always being non-null. 
*/
/*
If fortification mode, we warn about unused results of certain
   function calls which can lead to problems. 
*/
/* Forces a function to be always inlined.  */
/*
The Linux kernel defines __always_inline in stddef.h (283d7573), and
   it conflicts with this definition.  Therefore undefine it first to
   allow either header to be included first. 
*/
/*
Associate error messages with the source location of the call site rather
   than with the source location inside the function. 
*/
/*
GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
   inline semantics, unless -fgnu89-inline is used.  Using __GNUC_STDC_INLINE__
   or __GNUC_GNU_INLINE is not a good enough check for gcc because gcc versions
   older than 4.3 may define these macros and still not guarantee GNU inlining
   semantics.

   clang++ identifies itself as gcc-4.2, but has support for GNU inlining
   semantics, that can be checked for by using the __GNUC_STDC_INLINE_ and
   __GNUC_GNU_INLINE__ macro definitions. 
*/
/*
GCC 4.3 and above allow passing all anonymous arguments of an
   __extern_always_inline function to some other vararg function. 
*/
/*
It is possible to compile containing GCC extensions even if GCC is
   run in pedantic mode if the uses are carefully marked using the
   `__extension__' keyword.  But this is not generally available before
   version 2.8. 
*/
/*
__restrict is known in EGCS 1.2 and above, and in clang.
   It works also in C++ mode (outside of arrays), but only when spelled
   as '__restrict', not 'restrict'. 
*/
/*
ISO C99 also allows to declare arrays as non-overlapping.  The syntax is
     array_name[restrict]
   GCC 3.1 and clang support this.
   This syntax is not usable in C++ mode. 
*/
/*
Describes a char array whose address can safely be passed as the first
   argument to strncpy and strncat, as the char array is not necessarily
   a NUL-terminated string. 
*/
/* Undefine (also defined in libc-symbols.h).  */
/*
Copies attributes from the declaration or type referenced by
   the argument. 
*/
/*
The #ifndef lets Gnulib avoid including these on non-glibc
   platforms, where the includes typically do not exist. 
*/
/* Determine the wordsize from the preprocessor defines.  */
/* Both x86-64 and x32 use the 64-bit system call interface.  */
/*
Properties of long double type.  ldbl-96 version.
   Copyright (C) 2016-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it andor
   modify it under the terms of the GNU Lesser General Public
   License  published by the Free Software Foundation; either
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
long double is distinct from double, so there is nothing to
   define here. 
*/
/*
__glibc_macro_warning (MESSAGE) issues warning MESSAGE.  This is
   intended for use in preprocessor macros.

   Note: MESSAGE must be a _single_ string; concatenation of string
   literals is not supported. 
*/
/*
Generic selection (ISO C11) is a C-only feature, available in GCC
   since version 4.9.  Previous versions do not provide generic
   selection, even though they might set __STDC_VERSION__ to 201112L,
   when in -std=c11 mode.  Thus, we must check for !defined __GNUC__
   when testing __STDC_VERSION__ for generic selection support.
   On the other hand, Clang also defines __GNUC__, so a clang-specific
   check is required to enable the use of generic selection. 
*/
/*
Designates a 1-based positional argument ref-index of pointer type
   that can be used to access size-index elements of the pointed-to
   array according to access mode, or at least one element when
   size-index is not provided:
     access (access-mode, <ref-index> [, <size-index>]) 
*/
/*
Designates dealloc as a function to call to deallocate objects
   allocated by the declared function. 
*/
/*
Specify that a function such as setjmp or vfork may return
   twice. 
*/
/*
If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64].
*/
/* Decide whether we can define 'extern inline' functions in headers.  */
/*
This is here only because every header file already includes this one.
   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
   <gnustubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
   that will always return failure (and set errno to ENOSYS). 
*/
/*
This file is automatically generated.
   This file selects the right generated file of `__stub_FUNCTION' macros
   based on the architecture being compiled for. 
*/
/*
This file is automatically generated.
   It defines a symbol `__stub_FUNCTION' for each function
   in the C library which is a stub, meaning it will fail
   every time called, usually setting errno to ENOSYS. 
*/
/*
ISOIEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro. 
*/
/*
ISOIEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.) 
*/
/*
ISOIEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X. 
*/
/*
ISOIEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro. 
*/
/*
Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it andor modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http:www.gnu.org/licenses/>. 
*/
/*

 ISO C Standard:  7.17  Common definitions  <stddef.h>

*/
/*
Any one of these symbols __need_ means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done. 
*/
/*
This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage. 
*/
/*
Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it. 
*/
/*
On VxWorks, <typevxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected. 
*/
/*
In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2. 
*/
/* Signed type of difference of two pointers.  */
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/* Unsigned type of `sizeof' something.  */
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
typedef long unsigned int size_t;
/*
Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character. 
*/
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/* A null pointer constant.  */
/*
Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it andor modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http:www.gnu.org/licenses/>. 
*/
/*

 ISO C Standard:  7.15  Variable arguments  <stdarg.h>

*/
/* Define __gnuc_va_list.  */
typedef __builtin_va_list __gnuc_va_list;
/*
Define the standard macros for the user,
   if this invocation was from the user program. 
*/
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
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
/* Determine the wordsize from the preprocessor defines.  */
/* Both x86-64 and x32 use the 64-bit system call interface.  */
/*
Bit size of the time_t type at glibc build time, x86-64 and x32 case.
   Copyright (C) 2018-2021 Free Software Foundation, Inc.
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
/* For others, time size is word size.  */
/* Convenience types.  */
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
/* Fixed-size types, underlying types depend on word size and compiler.  */
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
/* Smallest types with at least a given width.  */
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
/* quad_t is also 64 bits.  */
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
/* Largest integral types.  */
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
/*
The machine-dependent file <bitstypesizes.h> defines __*_T_TYPE
   macros for each of the OS types we define below.  The definitions
   of those macros must use the following macros for underlying types.
   We define __S<SIZE>_TYPE and __U<SIZE>_TYPE for the signed and unsigned
   variants of each of the following integer types on this machine.

	16		-- "natural" 16-bit type (always short)
	32		-- "natural" 32-bit type (always int)
	64		-- "natural" 64-bit type (long or long long)
	LONG32		-- 32-bit type, traditionally long
	QUAD		-- 64-bit type, traditionally long long
	WORD		-- natural type of __WORDSIZE bits (int or long)
	LONGWORD	-- type of __WORDSIZE bits, traditionally long

   We distinguish WORD/LONGWORD, 32/LONG32, and 64/QUAD so that the
   conventional uses of `long' or `long long' type modifiers match the
   types we define, even when a less-adorned type would be the same size.
   This matters for (somewhat) portably writing printf/scanf formats for
   these types, where using the appropriate l or ll format modifiers can
   make the typedefs and the formats match up across all GNU platforms.  If
   we used `long' when it's 64 bits where `long long' is expected, then the
   compiler would warn about the formats not matching the argument types,
   and the programmer changing them to shut up the compiler would break the
   program's portability.

   Here we assume what is presently the case in all the GCC configurations
   we support: long long is always 64 bits, long is always word/address size,
   and int is always 32 bits. 
*/
/* No need to mark the typedef with __extension__.   */
/*
bitstypesizes.h -- underlying types for *_t.  Linux/x86-64 version.
   Copyright (C) 2012-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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
See <bitstypes.h> for the meaning of these macros.  This file exists so
   that <bits/types.h> need not vary across different GNU platforms. 
*/
/* X32 kernel interface is 64-bit.  */
/*
Tell the libc code that off_t and off64_t are actually the same type
   for all ABI purposes, even if possibly expressed as different base types
   for C type-checking purposes. 
*/
/* Same for ino_t and ino64_t.  */
/* And for __rlim_t and __rlim64_t.  */
/* And for fsblkcnt_t, fsblkcnt64_t, fsfilcnt_t and fsfilcnt64_t.  */
/* And for getitimer, setitimer and rusage  */
/* Number of descriptors that can fit in an `fd_set'.  */
/*
bitstime64.h -- underlying types for __time64_t.  Generic version.
   Copyright (C) 2018-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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
/* Define __TIME64_T_TYPE so that it is always a 64-bit type.  */
/* If we already have 64-bit time type then use it.  */
typedef unsigned long int __dev_t;
/* Type of device numbers.  */
typedef unsigned int __uid_t;
/* Type of user identifications.  */
typedef unsigned int __gid_t;
/* Type of group identifications.  */
typedef unsigned long int __ino_t;
/* Type of file serial numbers.  */
typedef unsigned long int __ino64_t;
/* Type of file serial numbers (LFS). */
typedef unsigned int __mode_t;
/* Type of file attribute bitmasks.  */
typedef unsigned long int __nlink_t;
/* Type of file link counts.  */
typedef long int __off_t;
/* Type of file sizes and offsets.  */
typedef long int __off64_t;
/* Type of file sizes and offsets (LFS).  */
typedef int __pid_t;
/* Type of process identifications.  */
struct named_test_ua_c_335
{
	int __val[2];
};

typedef struct named_test_ua_c_335 __fsid_t;
/* Type of file system IDs.  */
typedef long int __clock_t;
/* Type of CPU usage counts.  */
typedef unsigned long int __rlim_t;
/* Type for resource measurement.  */
typedef unsigned long int __rlim64_t;
/* Type for resource measurement (LFS).  */
typedef unsigned int __id_t;
/* General type for IDs.  */
typedef long int __time_t;
/* Seconds since the Epoch.  */
typedef unsigned int __useconds_t;
/* Count of microseconds.  */
typedef long int __suseconds_t;
/* Signed count of microseconds.  */
typedef long int __suseconds64_t;
typedef int __daddr_t;
/* The type of a disk address.  */
typedef int __key_t;
/* Type of an IPC key.  */
/* Clock ID used in clock and timer functions.  */
typedef int __clockid_t;
/* Timer ID returned by `timer_create'.  */
typedef void * __timer_t;
/* Type to represent block size.  */
typedef long int __blksize_t;
/* Types from the Large File Support interface.  */
/* Type to count number of disk blocks.  */
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
/* Type to count file system blocks.  */
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
/* Type to count file system nodes.  */
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
/* Type of miscellaneous file system fields.  */
typedef long int __fsword_t;
typedef long int __ssize_t;
/* Type of a byte count, or error.  */
/* Signed long type used in system calls.  */
typedef long int __syscall_slong_t;
/* Unsigned long type used in system calls.  */
typedef unsigned long int __syscall_ulong_t;
/*
These few don't really vary by system, they always correspond
   to one of the other defined types. 
*/
typedef __off64_t __loff_t;
/* Type of file sizes and offsets (LFS).  */
typedef char * __caddr_t;
/* Duplicates info from stdint.h but this is used in unistd.h.  */
typedef long int __intptr_t;
/* Duplicate info from syssocket.h.  */
typedef unsigned int __socklen_t;
/*
C99: An integer type that can be accessed as an atomic entity,
   even in the presence of asynchronous interrupts.
   It is not currently necessary for this to be machine-specific. 
*/
typedef int __sig_atomic_t;
/*
Seconds since the Epoch, visible to user code when time_t is too
   narrow only for consistency with the old way of widening too-narrow
   types.  User code should never use __time64_t. 
*/
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/*
Integral type unchanged by default argument promotions that can
   hold any value corresponding to members of the extended character
   set, as well as at least one value that does not correspond to any
   member of the extended character set. 
*/
/* Conversion state information.  */
union named_test_ua_c_614
{
	unsigned int __wch;
	char __wchb[4];
};

struct named_test_ua_c_606
{
	int __count;
	union named_test_ua_c_614 __value;
};

/* Value so far.  */
typedef struct named_test_ua_c_606 __mbstate_t;
/*
The tag name of this struct is _G_fpos_t to preserve historic
   C++ mangled names for functions taking fpos_t arguments.
   That name should not be used in new code. 
*/
struct _G_fpos_t
{
	__off_t __pos;
	__mbstate_t __state;
};

typedef struct _G_fpos_t __fpos_t;
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/*
The tag name of this struct is _G_fpos64_t to preserve historic
   C++ mangled names for functions taking fpos_t andor fpos64_t
   arguments.  That name should not be used in new code. 
*/
struct _G_fpos64_t
{
	__off64_t __pos;
	__mbstate_t __state;
};

typedef struct _G_fpos64_t __fpos64_t;
struct _IO_FILE;

typedef struct _IO_FILE __FILE;
struct _IO_FILE;

/* The opaque type of streams.  This is the definition used elsewhere.  */
typedef struct _IO_FILE FILE;
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
Caution: The contents of this file are not part of the official
   stdio.h API.  However, much of it is part of the officialbinary*
   interface, and therefore cannot be changed. 
*/
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
struct _IO_FILE;

struct _IO_marker;

struct _IO_codecvt;

struct _IO_wide_data;

/*
During the build of glibc itself, _IO_lock_t will already have been
   defined by internal headers. 
*/
typedef void _IO_lock_t;
/*
The tag name of this struct is _IO_FILE to preserve historic
   C++ mangled names for functions taking FILE arguments.
   That name should not be used in new code. 
*/
struct _IO_FILE
{
	int _flags;
	/* High-order word is _IO_MAGIC; rest is flags. */ 
	/* The following pointers correspond to the C++ streambuf protocol. */ 
	char * _IO_read_ptr;
	/* Current read pointer */ 
	char * _IO_read_end;
	/* End of get area. */ 
	char * _IO_read_base;
	/* Start of putback+get area. */ 
	char * _IO_write_base;
	/* Start of put area. */ 
	char * _IO_write_ptr;
	/* Current put pointer. */ 
	char * _IO_write_end;
	/* End of put area. */ 
	char * _IO_buf_base;
	/* Start of reserve area. */ 
	char * _IO_buf_end;
	/* End of reserve area. */ 
	/* The following fields are used to support backing up and undo. */ 
	char * _IO_save_base;
	/* Pointer to start of non-current get area. */ 
	char * _IO_backup_base;
	/* Pointer to first valid character of backup area */ 
	char * _IO_save_end;
	/* Pointer to end of non-current get area. */ 
	struct _IO_marker * _markers;
	struct _IO_FILE * _chain;
	int _fileno;
	int _flags2;
	__off_t _old_offset;
	/* This used to be _offset but it's too small.  */ 
	/* 1+column number of pbase(); 0 is unknown. */ 
	unsigned short _cur_column;
	signed char _vtable_offset;
	char _shortbuf[1];
	_IO_lock_t * _lock;
	__off64_t _offset;
	/* Wide character stream stuff.  */ 
	struct _IO_codecvt * _codecvt;
	struct _IO_wide_data * _wide_data;
	struct _IO_FILE * _freeres_list;
	void * _freeres_buf;
	size_t __pad5;
	int _mode;
	/* Make sure we don't get into trouble again.  */ 
	char _unused2[(((15*sizeof (int))-(4*sizeof (void * )))-sizeof (size_t))];
};

struct _IO_FILE;

/* These macros are used by bitsstdio.h and internal headers.  */
/* Many more flag bits are defined internally.  */
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;
/* The type of the second argument to `fgetpos' and `fsetpos'.  */
typedef __fpos_t fpos_t;
/* The possibilities for the third argument to `setvbuf'.  */
/* Default buffer size.  */
/*
The value returned by fgetc and similar functions to indicate the
   end of the file. 
*/
/*
The possibilities for the third argument to `fseek'.
   These values should not be changed. 
*/
/* Default path prefix for `tempnam' and `tmpnam'.  */
/*
Get the values:
   L_tmpnam	How long an array of chars must be to be passed to `tmpnam'.
   TMP_MAX	The minimum number of unique filenames generated by tmpnam
		(and tempnam when it uses tmpnam's name space),
		or tempnam (the two are separate).
   L_ctermid	How long an array to pass to `ctermid'.
   L_cuserid	How long an array to pass to `cuserid'.
   FOPEN_MAX	Minimum number of files that can be open at once.
   FILENAME_MAX	Maximum length of a filename. 
*/
/*
Copyright (C) 1994-2021 Free Software Foundation, Inc.
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
/* Standard streams.  */
extern FILE * stdin;
/* Standard input stream.  */
extern FILE * stdout;
/* Standard output stream.  */
extern FILE * stderr;
/* Standard error output stream.  */
/* C89C99 say they're macros.  Make them happy.  */
/* Remove file FILENAME.  */
extern int remove(const char * __filename);
/* Rename file OLD to NEW.  */
extern int rename(const char * __old, const char * __new);
/* Rename file OLD relative to OLDFD to NEW relative to NEWFD.  */
extern int renameat(int __oldfd, const char * __old, int __newfd, const char * __new);
/*
Close STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int fclose(FILE * __stream);
/*
Create a temporary file and open it readwrite.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern FILE *tmpfile(void );
/* Generate a temporary filename.  */
extern char *tmpnam(char [20]);
/*
This is the reentrant variant of `tmpnam'.  The only difference is
   that it does not allow S to be NULL. 
*/
extern char *tmpnam_r(char __s[20]);
/*
Generate a unique temporary filename using up to five characters of PFX
   if it is not NULL.  The directory to put this file in is searched for
   as follows: First the environment variable "TMPDIR" is checked.
   If it contains the name of a writable directory, that directory is used.
   If not and if DIR is not NULL, that value is checked.  If that fails,
   P_tmpdir is tried and finally "tmp".  The storage for the filename
   is allocated by `malloc'. 
*/
extern char *tempnam(const char * __dir, const char * __pfx);
/*
Flush STREAM, or all streams if STREAM is NULL.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int fflush(FILE * __stream);
/*
Faster versions when locking is not required.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW. 
*/
extern int fflush_unlocked(FILE * __stream);
/*
Open a file and create a new stream for it.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern FILE *fopen(const char * __filename, const char * __modes);
/*
Open a file, replacing an existing stream with it.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern FILE *freopen(const char * __filename, const char * __modes, FILE * __stream);
/* Create a new stream that refers to an existing system file descriptor.  */
extern FILE *fdopen(int __fd, const char * __modes);
/* Create a new stream that refers to a memory buffer.  */
extern FILE *fmemopen(void * __s, size_t __len, const char * __modes);
/*
Open a stream that writes into a malloc'd buffer that is expanded as
   necessary.BUFLOC and *SIZELOC are updated with the buffer's location
   and the number of characters written on fflush or fclose. 
*/
extern FILE *open_memstream(char * * __bufloc, size_t * __sizeloc);
/*
If BUF is NULL, make STREAM unbuffered.
   Else make it use buffer BUF, of size BUFSIZ. 
*/
extern void setbuf(FILE * __stream, char * __buf);
/*
Make STREAM use buffering mode MODE.
   If BUF is not NULL, use N bytes of it for buffering;
   else allocate an internal buffer N bytes long. 
*/
extern int setvbuf(FILE * __stream, char * __buf, int __modes, size_t __n);
/*
If BUF is NULL, make STREAM unbuffered.
   Else make it use SIZE bytes of BUF for buffering. 
*/
extern void setbuffer(FILE * __stream, char * __buf, size_t __size);
/* Make STREAM line-buffered.  */
extern void setlinebuf(FILE * __stream);
/*
Write formatted output to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int fprintf(FILE * __stream, const char * __format,  ...);
/*
Write formatted output to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int printf(const char * __format,  ...);
/* Write formatted output to S.  */
extern int sprintf(char * __s, const char * __format,  ...);
/*
Write formatted output to S from argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int vfprintf(FILE * __s, const char * __format, __gnuc_va_list __arg);
/*
Write formatted output to stdout from argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int vprintf(const char * __format, __gnuc_va_list __arg);
/* Write formatted output to S from argument list ARG.  */
extern int vsprintf(char * __s, const char * __format, __gnuc_va_list __arg);
/* Maximum chars of output to write in MAXLEN.  */
extern int snprintf(char * __s, size_t __maxlen, const char * __format,  ...);
extern int vsnprintf(char * __s, size_t __maxlen, const char * __format, __gnuc_va_list __arg);
/* Write formatted output to a file descriptor.  */
extern int vdprintf(int __fd, const char * __fmt, __gnuc_va_list __arg);
extern int dprintf(int __fd, const char * __fmt,  ...);
/*
Read formatted input from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int fscanf(FILE * __stream, const char * __format,  ...);
/*
Read formatted input from stdin.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int scanf(const char * __format,  ...);
/* Read formatted input from S.  */
extern int sscanf(const char * __s, const char * __format,  ...);
/*
For historical reasons, the C99-compliant versions of the scanf
   functions are at alternative names.  When __LDBL_COMPAT or
   __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI are in effect, this is handled in
   bitsstdio-ldbl.h. 
*/
/*
Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
Defined to 1 if the current compiler invocation provides a
   floating-point type with the IEEE 754 binary128 format, and this
   glibc includes correspondingf128 interfaces for it.  The required
   libgcc support was added some time after the basic compiler
   support, for x86_64 and x86. 
*/
/*
Defined to 1 if __HAVE_FLOAT128 is 1 and the type is ABI-distinct
   from the default float, double and long double types in this glibc. 
*/
/*
Defined to 1 if the current compiler invocation provides a
   floating-point type with the right format for _Float64x, and this
   glibc includes correspondingf64x interfaces for it. 
*/
/*
Defined to 1 if __HAVE_FLOAT64X is 1 and _Float64x has the format
   of long double.  Otherwise, if __HAVE_FLOAT64X is 1, _Float64x has
   the format of _Float128, which must be different from that of long
   double. 
*/
/*
Defined to concatenate the literal suffix to be used with _Float128
   types, if __HAVE_FLOAT128 is 1.
*/
/* Defined to a complex binary128 type if __HAVE_FLOAT128 is 1.  */
/* The remaining of this file provides support for older compilers.  */
/* The type _Float128 exists only since GCC 7.0.  */
/* __builtin_huge_valf128 doesn't exist before GCC 7.0.  */
/*
Older GCC has only a subset of built-in functions for _Float128 on
   x86, and __builtin_infq is not usable in static initializers.
   Converting a narrower sNaN to _Float128 produces a quiet NaN, so
   attempts to use _Float128 sNaNs will not work properly with older
   compilers. 
*/
/*
In mathmath.h, __MATH_TG will expand signbit to __builtin_signbit*,
   e.g.: __builtin_signbitf128, before GCC 6.  However, there has never
   been a __builtin_signbitf128 in GCC and the type-generic builtin is
   only available since GCC 6. 
*/
/*
Macros to control TS 18661-3 glibc features where the same
   definitions are appropriate for all platforms.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
Properties of long double type.  ldbl-96 version.
   Copyright (C) 2016-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it andor
   modify it under the terms of the GNU Lesser General Public
   License  published by the Free Software Foundation; either
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
long double is distinct from double, so there is nothing to
   define here. 
*/
/*
This header should be included at the bottom of each bitsfloatn.h.
   It defines the following macros for each _FloatN and _FloatNx type,
   where the same definitions, or definitions based only on the macros
   in bits/floatn.h, are appropriate for all glibc configurations. 
*/
/*
Defined to 1 if the current compiler invocation provides a
   floating-point type with the right format for this type, and this
   glibc includes correspondingfN or *fNx interfaces for it. 
*/
/*
Defined to 1 if the corresponding __HAVE_<type> macro is 1 and the
   type is the first with its format in the sequence of (the default
   choices for) float, double, long double, _Float16, _Float32,
   _Float64, _Float128, _Float32x, _Float64x, _Float128x for this
   glibc; that is, if functions present once per floating-point format
   rather than once per type are present for this type.

   All configurations supported by glibc have _Float32 the same format
   as float, _Float64 and _Float32x the same format as double, the
   _Float64x the same format as either long double or _Float128.  No
   configurations support _Float128x or, as of GCC 7, have compiler
   support for a type meeting the requirements for _Float128x. 
*/
/*
Defined to 1 if the corresponding _FloatN type is not binary compatible
   with the corresponding ISO C type in the current compilation unit as
   opposed to __HAVE_DISTINCT_FLOATN, which indicates the default types built
   in glibc. 
*/
/*
Defined to 1 if any _FloatN or _FloatNx types that are not
   ABI-distinct are however distinct types at the C language level (so
   for the purposes of __builtin_types_compatible_p and _Generic). 
*/
/*
Defined to concatenate the literal suffix to be used with _FloatN
   or _FloatNx types, if __HAVE_<type> is 1.  The corresponding
   literal suffixes exist since GCC 7, for C only. 
*/
/* Defined to a complex type if __HAVE_<type> is 1.  */
/* The remaining of this file provides support for older compilers.  */
/*
If double, long double and _Float64 all have the same set of
   values, TS 18661-3 requires the usual arithmetic conversions on
   long double and _Float64 to produce _Float64.  For this to be the
   case when building with a compiler without a distinct _Float64
   type, _Float64 must be a typedef for long double, not for
   double. 
*/
extern int fscanf(FILE * __stream, const char * __format,  ...);
extern int scanf(const char * __format,  ...);
extern int sscanf(const char * __s, const char * __format,  ...);
/*
Read formatted input from S into argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int vfscanf(FILE * __s, const char * __format, __gnuc_va_list __arg);
/*
Read formatted input from stdin into argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int vscanf(const char * __format, __gnuc_va_list __arg);
/* Read formatted input from S into argument list ARG.  */
extern int vsscanf(const char * __s, const char * __format, __gnuc_va_list __arg);
/* Same redirection as above for the vscanf family.  */
extern int vfscanf(FILE * __s, const char * __format, __gnuc_va_list __arg);
extern int vscanf(const char * __format, __gnuc_va_list __arg);
extern int vsscanf(const char * __s, const char * __format, __gnuc_va_list __arg);
/*
Read a character from STREAM.

   These functions are possible cancellation points and therefore not
   marked with __THROW. 
*/
extern int fgetc(FILE * __stream);
extern int getc(FILE * __stream);
/*
Read a character from stdin.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int getchar(void );
/*
These are defined in POSIX.1:1996.

   These functions are possible cancellation points and therefore not
   marked with __THROW. 
*/
extern int getc_unlocked(FILE * __stream);
extern int getchar_unlocked(void );
/*
Faster version when locking is not necessary.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW. 
*/
extern int fgetc_unlocked(FILE * __stream);
/*
Write a character to STREAM.

   These functions are possible cancellation points and therefore not
   marked with __THROW.

   These functions is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int fputc(int __c, FILE * __stream);
extern int putc(int __c, FILE * __stream);
/*
Write a character to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int putchar(int __c);
/*
Faster version when locking is not necessary.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW. 
*/
extern int fputc_unlocked(int __c, FILE * __stream);
/*
These are defined in POSIX.1:1996.

   These functions are possible cancellation points and therefore not
   marked with __THROW. 
*/
extern int putc_unlocked(int __c, FILE * __stream);
extern int putchar_unlocked(int __c);
/* Get a word (int) from STREAM.  */
extern int getw(FILE * __stream);
/* Write a word (int) to STREAM.  */
extern int putw(int __w, FILE * __stream);
/*
Get a newline-terminated string of finite length from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern char *fgets(char * __s, int __n, FILE * __stream);
/*
Read up to (and including) a DELIMITER from STREAM intoLINEPTR
   (and null-terminate it). *LINEPTR is a pointer returned from malloc (or
   NULL), pointing to *N characters of space.  It is realloc'd as
   necessary.  Returns the number of characters read (not including the
   null terminator), or -1 on error or EOF.

   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW. 
*/
extern __ssize_t __getdelim(char * * __lineptr, size_t * __n, int __delimiter, FILE * __stream);
extern __ssize_t getdelim(char * * __lineptr, size_t * __n, int __delimiter, FILE * __stream);
/*
Like `getdelim', but reads up to a newline.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW. 
*/
extern __ssize_t getline(char * * __lineptr, size_t * __n, FILE * __stream);
/*
Write a string to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int fputs(const char * __s, FILE * __stream);
/*
Write a string, followed by a newline, to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int puts(const char * __s);
/*
Push a character back onto the input buffer of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int ungetc(int __c, FILE * __stream);
/*
Read chunks of generic data from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern size_t fread(void * __ptr, size_t __size, size_t __n, FILE * __stream);
/*
Write chunks of generic data to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern size_t fwrite(const void * __ptr, size_t __size, size_t __n, FILE * __s);
/*
Faster versions when locking is not necessary.

   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW. 
*/
extern size_t fread_unlocked(void * __ptr, size_t __size, size_t __n, FILE * __stream);
extern size_t fwrite_unlocked(const void * __ptr, size_t __size, size_t __n, FILE * __stream);
/*
Seek to a certain position on STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int fseek(FILE * __stream, long int __off, int __whence);
/*
Return the current position of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern long int ftell(FILE * __stream);
/*
Rewind to the beginning of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern void rewind(FILE * __stream);
/*
The Single Unix Specification, Version 2, specifies an alternative,
   more adequate interface for the two functions above which deal with
   file offset.  `long int' is not the right type.  These definitions
   are originally defined in the Large File Support API. 
*/
/*
Seek to a certain position on STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int fseeko(FILE * __stream, __off_t __off, int __whence);
/*
Return the current position of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern __off_t ftello(FILE * __stream);
/*
Get STREAM's position.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int fgetpos(FILE * __stream, fpos_t * __pos);
/*
Set STREAM's position.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int fsetpos(FILE * __stream, const fpos_t * __pos);
/* Clear the error and EOF indicators for STREAM.  */
extern void clearerr(FILE * __stream);
/* Return the EOF indicator for STREAM.  */
extern int feof(FILE * __stream);
/* Return the error indicator for STREAM.  */
extern int ferror(FILE * __stream);
/* Faster versions when locking is not required.  */
extern void clearerr_unlocked(FILE * __stream);
extern int feof_unlocked(FILE * __stream);
extern int ferror_unlocked(FILE * __stream);
/*
Print a message describing the meaning of the value of errno.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern void perror(const char * __s);
/* Return the system file descriptor for STREAM.  */
extern int fileno(FILE * __stream);
/* Faster version when locking is not required.  */
extern int fileno_unlocked(FILE * __stream);
/*
Close a stream opened by popen and return the status of its child.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int pclose(FILE * __stream);
/*
Create a new stream connected to a pipe running the given command.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern FILE *popen(const char * __command, const char * __modes);
/* Return the name of the controlling terminal.  */
extern char *ctermid(char * __s);
/* These are defined in POSIX.1:1996.  */
/* Acquire ownership of STREAM.  */
extern void flockfile(FILE * __stream);
/*
Try to acquire ownership of STREAM but do not block if it is not
   possible. 
*/
extern int ftrylockfile(FILE * __stream);
/* Relinquish the ownership granted for STREAM.  */
extern void funlockfile(FILE * __stream);
/*
Slow-path routines used by the optimized inline functions in
   bitsstdio.h. 
*/
extern int __uflow(FILE * );
extern int __overflow(FILE * , int );
/*
If we are compiling with optimizing read this file.  It contains
   several optimizing inline functions and macros. 
*/
/*
Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
Declarations for math functions.
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

	ISO C99 Standard: 7.12 Mathematics	<math.h>

*/
/*
Handle feature test macros at the start of a header.
   Copyright (C) 2016-2021 Free Software Foundation, Inc.
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
This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included. 
*/
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
ISOIEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro. 
*/
/*
ISOIEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.) 
*/
/*
ISOIEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X. 
*/
/*
ISOIEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro. 
*/
/* Get definitions of __intmax_t and __uintmax_t.  */
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/* Get machine-dependent vector math functions declarations.  */
/*
Platform-specific SIMD declarations of math functions.
   Copyright (C) 2014-2021 Free Software Foundation, Inc.
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
/* Get default empty definitions for simd declarations.  */
/*
Empty definitions required for __MATHCALL_VEC unfolding in mathcalls.h.
   Copyright (C) 2014-2021 Free Software Foundation, Inc.
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
Needed definitions could be generated with:
   for func in $(grep __MATHCALL_VEC mathbits/mathcalls.h |		 sed -r "s|__MATHCALL_VEC.?\(||; s|,.*||"); do
o
     echo "#define __DECL_SIMD_${func}";
     echo "#define __DECL_SIMD_${func}f";
     echo "#define __DECL_SIMD_${func}l";
   done

*/
/* Gather machine dependent type support.  */
/*
Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
Value returned on overflow.  With IEEE 754 floating point, this is
   +Infinity, otherwise the largest representable positive value. 
*/
/* IEEE positive infinity.  */
/* IEEE Not A Number.  */
/* Get __GLIBC_FLT_EVAL_METHOD.  */
/*
Define __GLIBC_FLT_EVAL_METHOD.  x86 version.
   Copyright (C) 2016-2021 Free Software Foundation, Inc.
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
Define the following typedefs.

    float_t	floating-point type at least as wide as `float' used
		to evaluate `float' expressions
    double_t	floating-point type at least as wide as `double' used
		to evaluate `double' expressions

*/
typedef float float_t;
typedef double double_t;
/*
Define macros for the return values of ilogb and llogb, based on
   __FP_LOGB0_IS_MIN and __FP_LOGBNAN_IS_MIN.

    FP_ILOGB0	Expands to a value returned by `ilogb (0.0)'.
    FP_ILOGBNAN	Expands to a value returned by `ilogb (NAN)'.
    FP_LLOGB0	Expands to a value returned by `llogb (0.0)'.
    FP_LLOGBNAN	Expands to a value returned by `llogb (NAN)'.


*/
/*
Define __FP_LOGB0_IS_MIN and __FP_LOGBNAN_IS_MIN.  x86 version.
   Copyright (C) 2016-2021 Free Software Foundation, Inc.
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
Get the architecture specific values describing the floating-point
   evaluation.  The following symbols will get defined:

    FP_FAST_FMA
    FP_FAST_FMAF
    FP_FAST_FMAL
		If defined it indicates that the `fma' function
		generally executes about as fast as a multiply and an add.
		This macro is defined only iff the `fma' function is
		implemented directly with a hardware multiply-add instructions.

*/
/*
Define FP_FAST_ macros.
   Copyright (C) 2016-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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
The GCC 4.6 compiler will define __FP_FAST_FMA{,F,L} if the fma{,f,l}
   builtins are supported. 
*/
/*
The file <bitsmathcalls.h> contains the prototypes for all the
   actual math functions.  These macros are used for those prototypes,
   so we can easily declare each function as both `name' and `__name',
   and can declare the float versions `namef' and `__namef'. 
*/
/*
Ignore the alias by default.  The alias is only useful with
   redirections. 
*/
/*
Prototype declarations for math classification macros helpers.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
/* Classify given number.  */
extern int __fpclassify(double __value);
/* Test for negative number.  */
extern int __signbit(double __value);
/*
Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity. 
*/
extern int __isinf(double __value);
/* Return nonzero if VALUE is finite and not NaN.  Used by isfinite macro.  */
extern int __finite(double __value);
/* Return nonzero if VALUE is not a number.  */
extern int __isnan(double __value);
/* Test equality.  */
extern int __iseqsig(double __x, double __y);
/* Test for signaling NaN.  */
extern int __issignaling(double __value);
/*
Prototype declarations for math functions; helper file for <math.h>.
   Copyright (C) 1996-2021 Free Software Foundation, Inc.
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
NOTE: Because of the special way this file is used by <math.h>, this
   file must NOT be protected from multiple inclusion as header files
   usually are.

   This file provides prototype declarations for the math functions.
   Most functions are declared using the macro:

   __MATHCALL (NAME,[_r], (ARGS...));

   This means there is a function `NAME' returning `double' and a function
   `NAMEf' returning `float'.  Each place `_Mdouble_' appears in the
   prototype, that is actually `double' in the prototype for `NAME' and
   `float' in the prototype for `NAMEf'.  Reentrant variant functions are
   called `NAME_r' and `NAMEf_r'.

   Functions returning other types like `int' are declared using the macro:

   __MATHDECL (TYPE, NAME,[_r], (ARGS...));

   This is just like __MATHCALL but for a function returning `TYPE'
   instead of `_Mdouble_'.  In all of these cases, there is still
   both a `NAME' and a `NAMEf' that takes `float' arguments.

   Note that there must be no whitespace before the argument passed for
   NAME, to make token pasting work with -traditional. 
*/
/* Trigonometric functions.  */
/* Arc cosine of X.  */
extern double acos(double __x);
extern double __acos(double __x);
/* Arc sine of X.  */
extern double asin(double __x);
extern double __asin(double __x);
/* Arc tangent of X.  */
extern double atan(double __x);
extern double __atan(double __x);
/* Arc tangent of YX.  */
extern double atan2(double __y, double __x);
extern double __atan2(double __y, double __x);
/* Cosine of X.  */
extern double cos(double __x);
extern double __cos(double __x);
/* Sine of X.  */
extern double sin(double __x);
extern double __sin(double __x);
/* Tangent of X.  */
extern double tan(double __x);
extern double __tan(double __x);
/* Hyperbolic functions.  */
/* Hyperbolic cosine of X.  */
extern double cosh(double __x);
extern double __cosh(double __x);
/* Hyperbolic sine of X.  */
extern double sinh(double __x);
extern double __sinh(double __x);
/* Hyperbolic tangent of X.  */
extern double tanh(double __x);
extern double __tanh(double __x);
/* Hyperbolic arc cosine of X.  */
extern double acosh(double __x);
extern double __acosh(double __x);
/* Hyperbolic arc sine of X.  */
extern double asinh(double __x);
extern double __asinh(double __x);
/* Hyperbolic arc tangent of X.  */
extern double atanh(double __x);
extern double __atanh(double __x);
/* Exponential and logarithmic functions.  */
/* Exponential function of X.  */
extern double exp(double __x);
extern double __exp(double __x);
/* Break VALUE into a normalized fraction and an integral power of 2.  */
extern double frexp(double __x, int * __exponent);
extern double __frexp(double __x, int * __exponent);
/* X times (two to the EXP power).  */
extern double ldexp(double __x, int __exponent);
extern double __ldexp(double __x, int __exponent);
/* Natural logarithm of X.  */
extern double log(double __x);
extern double __log(double __x);
/* Base-ten logarithm of X.  */
extern double log10(double __x);
extern double __log10(double __x);
/* Break VALUE into integral and fractional parts.  */
extern double modf(double __x, double * __iptr);
extern double __modf(double __x, double * __iptr);
/* Return exp(X) - 1.  */
extern double expm1(double __x);
extern double __expm1(double __x);
/* Return log(1 + X).  */
extern double log1p(double __x);
extern double __log1p(double __x);
/* Return the base 2 signed integral exponent of X.  */
extern double logb(double __x);
extern double __logb(double __x);
/* Compute base-2 exponential of X.  */
extern double exp2(double __x);
extern double __exp2(double __x);
/* Compute base-2 logarithm of X.  */
extern double log2(double __x);
extern double __log2(double __x);
/* Power functions.  */
/* Return X to the Y power.  */
extern double pow(double __x, double __y);
extern double __pow(double __x, double __y);
/* Return the square root of X.  */
extern double sqrt(double __x);
extern double __sqrt(double __x);
/* Return `sqrt(XX + Y*Y)'.  */
extern double hypot(double __x, double __y);
extern double __hypot(double __x, double __y);
/* Return the cube root of X.  */
extern double cbrt(double __x);
extern double __cbrt(double __x);
/* Nearest integer, absolute value, and remainder functions.  */
/* Smallest integral value not less than X.  */
extern double ceil(double __x);
extern double __ceil(double __x);
/* Absolute value of X.  */
extern double fabs(double __x);
extern double __fabs(double __x);
/* Largest integer not greater than X.  */
extern double floor(double __x);
extern double __floor(double __x);
/* Floating-point modulo remainder of XY.  */
extern double fmod(double __x, double __y);
extern double __fmod(double __x, double __y);
/*
Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity. 
*/
extern int isinf(double __value);
/* Return nonzero if VALUE is finite and not NaN.  */
extern int finite(double __value);
/* Return the remainder of XY.  */
extern double drem(double __x, double __y);
extern double __drem(double __x, double __y);
/* Return the fractional part of X after dividing out `ilogb (X)'.  */
extern double significand(double __x);
extern double __significand(double __x);
/* Return X with its signed changed to Y's.  */
extern double copysign(double __x, double __y);
extern double __copysign(double __x, double __y);
/* Return representation of qNaN for double type.  */
extern double nan(const char * __tagb);
extern double __nan(const char * __tagb);
/* Return nonzero if VALUE is not a number.  */
extern int isnan(double __value);
/* Bessel functions.  */
extern double j0(double );
extern double __j0(double );
extern double j1(double );
extern double __j1(double );
extern double jn(int , double );
extern double __jn(int , double );
extern double y0(double );
extern double __y0(double );
extern double y1(double );
extern double __y1(double );
extern double yn(int , double );
extern double __yn(int , double );
/* Error and gamma functions.  */
extern double erf(double );
extern double __erf(double );
extern double erfc(double );
extern double __erfc(double );
extern double lgamma(double );
extern double __lgamma(double );
/* True gamma function.  */
extern double tgamma(double );
extern double __tgamma(double );
/* Obsolete alias for `lgamma'.  */
extern double gamma(double );
extern double __gamma(double );
/*
Reentrant version of lgamma.  This function uses the global variable
   `signgam'.  The reentrant version instead takes a pointer and stores
   the value through it. 
*/
extern double lgamma_r(double , int * __signgamp);
extern double __lgamma_r(double , int * __signgamp);
/*
Return the integer nearest X in the direction of the
   prevailing rounding mode. 
*/
extern double rint(double __x);
extern double __rint(double __x);
/* Return X + epsilon if X < Y, X - epsilon if X > Y.  */
extern double nextafter(double __x, double __y);
extern double __nextafter(double __x, double __y);
extern double nexttoward(double __x, long double __y);
extern double __nexttoward(double __x, long double __y);
/* Return the remainder of integer divison X Y with infinite precision.  */
extern double remainder(double __x, double __y);
extern double __remainder(double __x, double __y);
/* Return X times (2 to the Nth power).  */
extern double scalbn(double __x, int __n);
extern double __scalbn(double __x, int __n);
/* Return the binary exponent of X, which must be nonzero.  */
extern int ilogb(double __x);
extern int __ilogb(double __x);
/* Return X times (2 to the Nth power).  */
extern double scalbln(double __x, long int __n);
extern double __scalbln(double __x, long int __n);
/*
Round X to integral value in floating-point format using current
   rounding direction, but do not raise inexact exception. 
*/
extern double nearbyint(double __x);
extern double __nearbyint(double __x);
/*
Round X to nearest integral value, rounding halfway cases away from
   zero. 
*/
extern double round(double __x);
extern double __round(double __x);
/*
Round X to the integral value in floating-point format nearest but
   not larger in magnitude. 
*/
extern double trunc(double __x);
extern double __trunc(double __x);
/*
Compute remainder of X and Y and put inQUO a value with sign of x/y
   and magnitude congruent `mod 2^n' to the magnitude of the integral
   quotient x/y, with n >= 3. 
*/
extern double remquo(double __x, double __y, int * __quo);
extern double __remquo(double __x, double __y, int * __quo);
/* Conversion functions.  */
/*
Round X to nearest integral value according to current rounding
   direction. 
*/
extern long int lrint(double __x);
extern long int __lrint(double __x);
extern long long int llrint(double __x);
extern long long int __llrint(double __x);
/*
Round X to nearest integral value, rounding halfway cases away from
   zero. 
*/
extern long int lround(double __x);
extern long int __lround(double __x);
extern long long int llround(double __x);
extern long long int __llround(double __x);
/* Return positive difference between X and Y.  */
extern double fdim(double __x, double __y);
extern double __fdim(double __x, double __y);
/* Return maximum numeric value from X and Y.  */
extern double fmax(double __x, double __y);
extern double __fmax(double __x, double __y);
/* Return minimum numeric value from X and Y.  */
extern double fmin(double __x, double __y);
extern double __fmin(double __x, double __y);
/* Multiply-add function computed as a ternary operation.  */
extern double fma(double __x, double __y, double __z);
extern double __fma(double __x, double __y, double __z);
/* Return X times (2 to the Nth power).  */
extern double scalb(double __x, double __n);
extern double __scalb(double __x, double __n);
/*
Include the file of declarations again, this time using `float'
   instead of `double' and appending f to each function name. 
*/
/*
Prototype declarations for math classification macros helpers.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
/* Classify given number.  */
extern int __fpclassifyf(float __value);
/* Test for negative number.  */
extern int __signbitf(float __value);
/*
Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity. 
*/
extern int __isinff(float __value);
/* Return nonzero if VALUE is finite and not NaN.  Used by isfinite macro.  */
extern int __finitef(float __value);
/* Return nonzero if VALUE is not a number.  */
extern int __isnanf(float __value);
/* Test equality.  */
extern int __iseqsigf(float __x, float __y);
/* Test for signaling NaN.  */
extern int __issignalingf(float __value);
/*
Prototype declarations for math functions; helper file for <math.h>.
   Copyright (C) 1996-2021 Free Software Foundation, Inc.
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
NOTE: Because of the special way this file is used by <math.h>, this
   file must NOT be protected from multiple inclusion as header files
   usually are.

   This file provides prototype declarations for the math functions.
   Most functions are declared using the macro:

   __MATHCALL (NAME,[_r], (ARGS...));

   This means there is a function `NAME' returning `double' and a function
   `NAMEf' returning `float'.  Each place `_Mdouble_' appears in the
   prototype, that is actually `double' in the prototype for `NAME' and
   `float' in the prototype for `NAMEf'.  Reentrant variant functions are
   called `NAME_r' and `NAMEf_r'.

   Functions returning other types like `int' are declared using the macro:

   __MATHDECL (TYPE, NAME,[_r], (ARGS...));

   This is just like __MATHCALL but for a function returning `TYPE'
   instead of `_Mdouble_'.  In all of these cases, there is still
   both a `NAME' and a `NAMEf' that takes `float' arguments.

   Note that there must be no whitespace before the argument passed for
   NAME, to make token pasting work with -traditional. 
*/
/* Trigonometric functions.  */
/* Arc cosine of X.  */
extern float acosf(float __x);
extern float __acosf(float __x);
/* Arc sine of X.  */
extern float asinf(float __x);
extern float __asinf(float __x);
/* Arc tangent of X.  */
extern float atanf(float __x);
extern float __atanf(float __x);
/* Arc tangent of YX.  */
extern float atan2f(float __y, float __x);
extern float __atan2f(float __y, float __x);
/* Cosine of X.  */
extern float cosf(float __x);
extern float __cosf(float __x);
/* Sine of X.  */
extern float sinf(float __x);
extern float __sinf(float __x);
/* Tangent of X.  */
extern float tanf(float __x);
extern float __tanf(float __x);
/* Hyperbolic functions.  */
/* Hyperbolic cosine of X.  */
extern float coshf(float __x);
extern float __coshf(float __x);
/* Hyperbolic sine of X.  */
extern float sinhf(float __x);
extern float __sinhf(float __x);
/* Hyperbolic tangent of X.  */
extern float tanhf(float __x);
extern float __tanhf(float __x);
/* Hyperbolic arc cosine of X.  */
extern float acoshf(float __x);
extern float __acoshf(float __x);
/* Hyperbolic arc sine of X.  */
extern float asinhf(float __x);
extern float __asinhf(float __x);
/* Hyperbolic arc tangent of X.  */
extern float atanhf(float __x);
extern float __atanhf(float __x);
/* Exponential and logarithmic functions.  */
/* Exponential function of X.  */
extern float expf(float __x);
extern float __expf(float __x);
/* Break VALUE into a normalized fraction and an integral power of 2.  */
extern float frexpf(float __x, int * __exponent);
extern float __frexpf(float __x, int * __exponent);
/* X times (two to the EXP power).  */
extern float ldexpf(float __x, int __exponent);
extern float __ldexpf(float __x, int __exponent);
/* Natural logarithm of X.  */
extern float logf(float __x);
extern float __logf(float __x);
/* Base-ten logarithm of X.  */
extern float log10f(float __x);
extern float __log10f(float __x);
/* Break VALUE into integral and fractional parts.  */
extern float modff(float __x, float * __iptr);
extern float __modff(float __x, float * __iptr);
/* Return exp(X) - 1.  */
extern float expm1f(float __x);
extern float __expm1f(float __x);
/* Return log(1 + X).  */
extern float log1pf(float __x);
extern float __log1pf(float __x);
/* Return the base 2 signed integral exponent of X.  */
extern float logbf(float __x);
extern float __logbf(float __x);
/* Compute base-2 exponential of X.  */
extern float exp2f(float __x);
extern float __exp2f(float __x);
/* Compute base-2 logarithm of X.  */
extern float log2f(float __x);
extern float __log2f(float __x);
/* Power functions.  */
/* Return X to the Y power.  */
extern float powf(float __x, float __y);
extern float __powf(float __x, float __y);
/* Return the square root of X.  */
extern float sqrtf(float __x);
extern float __sqrtf(float __x);
/* Return `sqrt(XX + Y*Y)'.  */
extern float hypotf(float __x, float __y);
extern float __hypotf(float __x, float __y);
/* Return the cube root of X.  */
extern float cbrtf(float __x);
extern float __cbrtf(float __x);
/* Nearest integer, absolute value, and remainder functions.  */
/* Smallest integral value not less than X.  */
extern float ceilf(float __x);
extern float __ceilf(float __x);
/* Absolute value of X.  */
extern float fabsf(float __x);
extern float __fabsf(float __x);
/* Largest integer not greater than X.  */
extern float floorf(float __x);
extern float __floorf(float __x);
/* Floating-point modulo remainder of XY.  */
extern float fmodf(float __x, float __y);
extern float __fmodf(float __x, float __y);
/*
Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity. 
*/
extern int isinff(float __value);
/* Return nonzero if VALUE is finite and not NaN.  */
extern int finitef(float __value);
/* Return the remainder of XY.  */
extern float dremf(float __x, float __y);
extern float __dremf(float __x, float __y);
/* Return the fractional part of X after dividing out `ilogb (X)'.  */
extern float significandf(float __x);
extern float __significandf(float __x);
/* Return X with its signed changed to Y's.  */
extern float copysignf(float __x, float __y);
extern float __copysignf(float __x, float __y);
/* Return representation of qNaN for double type.  */
extern float nanf(const char * __tagb);
extern float __nanf(const char * __tagb);
/* Return nonzero if VALUE is not a number.  */
extern int isnanf(float __value);
/* Bessel functions.  */
extern float j0f(float );
extern float __j0f(float );
extern float j1f(float );
extern float __j1f(float );
extern float jnf(int , float );
extern float __jnf(int , float );
extern float y0f(float );
extern float __y0f(float );
extern float y1f(float );
extern float __y1f(float );
extern float ynf(int , float );
extern float __ynf(int , float );
/* Error and gamma functions.  */
extern float erff(float );
extern float __erff(float );
extern float erfcf(float );
extern float __erfcf(float );
extern float lgammaf(float );
extern float __lgammaf(float );
/* True gamma function.  */
extern float tgammaf(float );
extern float __tgammaf(float );
/* Obsolete alias for `lgamma'.  */
extern float gammaf(float );
extern float __gammaf(float );
/*
Reentrant version of lgamma.  This function uses the global variable
   `signgam'.  The reentrant version instead takes a pointer and stores
   the value through it. 
*/
extern float lgammaf_r(float , int * __signgamp);
extern float __lgammaf_r(float , int * __signgamp);
/*
Return the integer nearest X in the direction of the
   prevailing rounding mode. 
*/
extern float rintf(float __x);
extern float __rintf(float __x);
/* Return X + epsilon if X < Y, X - epsilon if X > Y.  */
extern float nextafterf(float __x, float __y);
extern float __nextafterf(float __x, float __y);
extern float nexttowardf(float __x, long double __y);
extern float __nexttowardf(float __x, long double __y);
/* Return the remainder of integer divison X Y with infinite precision.  */
extern float remainderf(float __x, float __y);
extern float __remainderf(float __x, float __y);
/* Return X times (2 to the Nth power).  */
extern float scalbnf(float __x, int __n);
extern float __scalbnf(float __x, int __n);
/* Return the binary exponent of X, which must be nonzero.  */
extern int ilogbf(float __x);
extern int __ilogbf(float __x);
/* Return X times (2 to the Nth power).  */
extern float scalblnf(float __x, long int __n);
extern float __scalblnf(float __x, long int __n);
/*
Round X to integral value in floating-point format using current
   rounding direction, but do not raise inexact exception. 
*/
extern float nearbyintf(float __x);
extern float __nearbyintf(float __x);
/*
Round X to nearest integral value, rounding halfway cases away from
   zero. 
*/
extern float roundf(float __x);
extern float __roundf(float __x);
/*
Round X to the integral value in floating-point format nearest but
   not larger in magnitude. 
*/
extern float truncf(float __x);
extern float __truncf(float __x);
/*
Compute remainder of X and Y and put inQUO a value with sign of x/y
   and magnitude congruent `mod 2^n' to the magnitude of the integral
   quotient x/y, with n >= 3. 
*/
extern float remquof(float __x, float __y, int * __quo);
extern float __remquof(float __x, float __y, int * __quo);
/* Conversion functions.  */
/*
Round X to nearest integral value according to current rounding
   direction. 
*/
extern long int lrintf(float __x);
extern long int __lrintf(float __x);
extern long long int llrintf(float __x);
extern long long int __llrintf(float __x);
/*
Round X to nearest integral value, rounding halfway cases away from
   zero. 
*/
extern long int lroundf(float __x);
extern long int __lroundf(float __x);
extern long long int llroundf(float __x);
extern long long int __llroundf(float __x);
/* Return positive difference between X and Y.  */
extern float fdimf(float __x, float __y);
extern float __fdimf(float __x, float __y);
/* Return maximum numeric value from X and Y.  */
extern float fmaxf(float __x, float __y);
extern float __fmaxf(float __x, float __y);
/* Return minimum numeric value from X and Y.  */
extern float fminf(float __x, float __y);
extern float __fminf(float __x, float __y);
/* Multiply-add function computed as a ternary operation.  */
extern float fmaf(float __x, float __y, float __z);
extern float __fmaf(float __x, float __y, float __z);
/* Return X times (2 to the Nth power).  */
extern float scalbf(float __x, float __n);
extern float __scalbf(float __x, float __n);
/*
Include the file of declarations again, this time using `long double'
   instead of `double' and appending l to each function name. 
*/
/*
Prototype declarations for math classification macros helpers.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
/* Classify given number.  */
extern int __fpclassifyl(long double __value);
/* Test for negative number.  */
extern int __signbitl(long double __value);
/*
Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity. 
*/
extern int __isinfl(long double __value);
/* Return nonzero if VALUE is finite and not NaN.  Used by isfinite macro.  */
extern int __finitel(long double __value);
/* Return nonzero if VALUE is not a number.  */
extern int __isnanl(long double __value);
/* Test equality.  */
extern int __iseqsigl(long double __x, long double __y);
/* Test for signaling NaN.  */
extern int __issignalingl(long double __value);
/*
Prototype declarations for math functions; helper file for <math.h>.
   Copyright (C) 1996-2021 Free Software Foundation, Inc.
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
NOTE: Because of the special way this file is used by <math.h>, this
   file must NOT be protected from multiple inclusion as header files
   usually are.

   This file provides prototype declarations for the math functions.
   Most functions are declared using the macro:

   __MATHCALL (NAME,[_r], (ARGS...));

   This means there is a function `NAME' returning `double' and a function
   `NAMEf' returning `float'.  Each place `_Mdouble_' appears in the
   prototype, that is actually `double' in the prototype for `NAME' and
   `float' in the prototype for `NAMEf'.  Reentrant variant functions are
   called `NAME_r' and `NAMEf_r'.

   Functions returning other types like `int' are declared using the macro:

   __MATHDECL (TYPE, NAME,[_r], (ARGS...));

   This is just like __MATHCALL but for a function returning `TYPE'
   instead of `_Mdouble_'.  In all of these cases, there is still
   both a `NAME' and a `NAMEf' that takes `float' arguments.

   Note that there must be no whitespace before the argument passed for
   NAME, to make token pasting work with -traditional. 
*/
/* Trigonometric functions.  */
/* Arc cosine of X.  */
extern long double acosl(long double __x);
extern long double __acosl(long double __x);
/* Arc sine of X.  */
extern long double asinl(long double __x);
extern long double __asinl(long double __x);
/* Arc tangent of X.  */
extern long double atanl(long double __x);
extern long double __atanl(long double __x);
/* Arc tangent of YX.  */
extern long double atan2l(long double __y, long double __x);
extern long double __atan2l(long double __y, long double __x);
/* Cosine of X.  */
extern long double cosl(long double __x);
extern long double __cosl(long double __x);
/* Sine of X.  */
extern long double sinl(long double __x);
extern long double __sinl(long double __x);
/* Tangent of X.  */
extern long double tanl(long double __x);
extern long double __tanl(long double __x);
/* Hyperbolic functions.  */
/* Hyperbolic cosine of X.  */
extern long double coshl(long double __x);
extern long double __coshl(long double __x);
/* Hyperbolic sine of X.  */
extern long double sinhl(long double __x);
extern long double __sinhl(long double __x);
/* Hyperbolic tangent of X.  */
extern long double tanhl(long double __x);
extern long double __tanhl(long double __x);
/* Hyperbolic arc cosine of X.  */
extern long double acoshl(long double __x);
extern long double __acoshl(long double __x);
/* Hyperbolic arc sine of X.  */
extern long double asinhl(long double __x);
extern long double __asinhl(long double __x);
/* Hyperbolic arc tangent of X.  */
extern long double atanhl(long double __x);
extern long double __atanhl(long double __x);
/* Exponential and logarithmic functions.  */
/* Exponential function of X.  */
extern long double expl(long double __x);
extern long double __expl(long double __x);
/* Break VALUE into a normalized fraction and an integral power of 2.  */
extern long double frexpl(long double __x, int * __exponent);
extern long double __frexpl(long double __x, int * __exponent);
/* X times (two to the EXP power).  */
extern long double ldexpl(long double __x, int __exponent);
extern long double __ldexpl(long double __x, int __exponent);
/* Natural logarithm of X.  */
extern long double logl(long double __x);
extern long double __logl(long double __x);
/* Base-ten logarithm of X.  */
extern long double log10l(long double __x);
extern long double __log10l(long double __x);
/* Break VALUE into integral and fractional parts.  */
extern long double modfl(long double __x, long double * __iptr);
extern long double __modfl(long double __x, long double * __iptr);
/* Return exp(X) - 1.  */
extern long double expm1l(long double __x);
extern long double __expm1l(long double __x);
/* Return log(1 + X).  */
extern long double log1pl(long double __x);
extern long double __log1pl(long double __x);
/* Return the base 2 signed integral exponent of X.  */
extern long double logbl(long double __x);
extern long double __logbl(long double __x);
/* Compute base-2 exponential of X.  */
extern long double exp2l(long double __x);
extern long double __exp2l(long double __x);
/* Compute base-2 logarithm of X.  */
extern long double log2l(long double __x);
extern long double __log2l(long double __x);
/* Power functions.  */
/* Return X to the Y power.  */
extern long double powl(long double __x, long double __y);
extern long double __powl(long double __x, long double __y);
/* Return the square root of X.  */
extern long double sqrtl(long double __x);
extern long double __sqrtl(long double __x);
/* Return `sqrt(XX + Y*Y)'.  */
extern long double hypotl(long double __x, long double __y);
extern long double __hypotl(long double __x, long double __y);
/* Return the cube root of X.  */
extern long double cbrtl(long double __x);
extern long double __cbrtl(long double __x);
/* Nearest integer, absolute value, and remainder functions.  */
/* Smallest integral value not less than X.  */
extern long double ceill(long double __x);
extern long double __ceill(long double __x);
/* Absolute value of X.  */
extern long double fabsl(long double __x);
extern long double __fabsl(long double __x);
/* Largest integer not greater than X.  */
extern long double floorl(long double __x);
extern long double __floorl(long double __x);
/* Floating-point modulo remainder of XY.  */
extern long double fmodl(long double __x, long double __y);
extern long double __fmodl(long double __x, long double __y);
/*
Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity. 
*/
extern int isinfl(long double __value);
/* Return nonzero if VALUE is finite and not NaN.  */
extern int finitel(long double __value);
/* Return the remainder of XY.  */
extern long double dreml(long double __x, long double __y);
extern long double __dreml(long double __x, long double __y);
/* Return the fractional part of X after dividing out `ilogb (X)'.  */
extern long double significandl(long double __x);
extern long double __significandl(long double __x);
/* Return X with its signed changed to Y's.  */
extern long double copysignl(long double __x, long double __y);
extern long double __copysignl(long double __x, long double __y);
/* Return representation of qNaN for double type.  */
extern long double nanl(const char * __tagb);
extern long double __nanl(const char * __tagb);
/* Return nonzero if VALUE is not a number.  */
extern int isnanl(long double __value);
/* Bessel functions.  */
extern long double j0l(long double );
extern long double __j0l(long double );
extern long double j1l(long double );
extern long double __j1l(long double );
extern long double jnl(int , long double );
extern long double __jnl(int , long double );
extern long double y0l(long double );
extern long double __y0l(long double );
extern long double y1l(long double );
extern long double __y1l(long double );
extern long double ynl(int , long double );
extern long double __ynl(int , long double );
/* Error and gamma functions.  */
extern long double erfl(long double );
extern long double __erfl(long double );
extern long double erfcl(long double );
extern long double __erfcl(long double );
extern long double lgammal(long double );
extern long double __lgammal(long double );
/* True gamma function.  */
extern long double tgammal(long double );
extern long double __tgammal(long double );
/* Obsolete alias for `lgamma'.  */
extern long double gammal(long double );
extern long double __gammal(long double );
/*
Reentrant version of lgamma.  This function uses the global variable
   `signgam'.  The reentrant version instead takes a pointer and stores
   the value through it. 
*/
extern long double lgammal_r(long double , int * __signgamp);
extern long double __lgammal_r(long double , int * __signgamp);
/*
Return the integer nearest X in the direction of the
   prevailing rounding mode. 
*/
extern long double rintl(long double __x);
extern long double __rintl(long double __x);
/* Return X + epsilon if X < Y, X - epsilon if X > Y.  */
extern long double nextafterl(long double __x, long double __y);
extern long double __nextafterl(long double __x, long double __y);
extern long double nexttowardl(long double __x, long double __y);
extern long double __nexttowardl(long double __x, long double __y);
/* Return the remainder of integer divison X Y with infinite precision.  */
extern long double remainderl(long double __x, long double __y);
extern long double __remainderl(long double __x, long double __y);
/* Return X times (2 to the Nth power).  */
extern long double scalbnl(long double __x, int __n);
extern long double __scalbnl(long double __x, int __n);
/* Return the binary exponent of X, which must be nonzero.  */
extern int ilogbl(long double __x);
extern int __ilogbl(long double __x);
/* Return X times (2 to the Nth power).  */
extern long double scalblnl(long double __x, long int __n);
extern long double __scalblnl(long double __x, long int __n);
/*
Round X to integral value in floating-point format using current
   rounding direction, but do not raise inexact exception. 
*/
extern long double nearbyintl(long double __x);
extern long double __nearbyintl(long double __x);
/*
Round X to nearest integral value, rounding halfway cases away from
   zero. 
*/
extern long double roundl(long double __x);
extern long double __roundl(long double __x);
/*
Round X to the integral value in floating-point format nearest but
   not larger in magnitude. 
*/
extern long double truncl(long double __x);
extern long double __truncl(long double __x);
/*
Compute remainder of X and Y and put inQUO a value with sign of x/y
   and magnitude congruent `mod 2^n' to the magnitude of the integral
   quotient x/y, with n >= 3. 
*/
extern long double remquol(long double __x, long double __y, int * __quo);
extern long double __remquol(long double __x, long double __y, int * __quo);
/* Conversion functions.  */
/*
Round X to nearest integral value according to current rounding
   direction. 
*/
extern long int lrintl(long double __x);
extern long int __lrintl(long double __x);
extern long long int llrintl(long double __x);
extern long long int __llrintl(long double __x);
/*
Round X to nearest integral value, rounding halfway cases away from
   zero. 
*/
extern long int lroundl(long double __x);
extern long int __lroundl(long double __x);
extern long long int llroundl(long double __x);
extern long long int __llroundl(long double __x);
/* Return positive difference between X and Y.  */
extern long double fdiml(long double __x, long double __y);
extern long double __fdiml(long double __x, long double __y);
/* Return maximum numeric value from X and Y.  */
extern long double fmaxl(long double __x, long double __y);
extern long double __fmaxl(long double __x, long double __y);
/* Return minimum numeric value from X and Y.  */
extern long double fminl(long double __x, long double __y);
extern long double __fminl(long double __x, long double __y);
/* Multiply-add function computed as a ternary operation.  */
extern long double fmal(long double __x, long double __y, long double __z);
extern long double __fmal(long double __x, long double __y, long double __z);
/* Return X times (2 to the Nth power).  */
extern long double scalbl(long double __x, long double __n);
extern long double __scalbl(long double __x, long double __n);
/*
Include the file of declarations for _FloatN and _FloatNx
   types. 
*/
/*
Prototype declarations for math classification macros helpers.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
/* Classify given number.  */
extern int __fpclassifyf128(float __value);
/* Test for negative number.  */
extern int __signbitf128(float __value);
/*
Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity. 
*/
extern int __isinff128(float __value);
/* Return nonzero if VALUE is finite and not NaN.  Used by isfinite macro.  */
extern int __finitef128(float __value);
/* Return nonzero if VALUE is not a number.  */
extern int __isnanf128(float __value);
/* Test equality.  */
extern int __iseqsigf128(float __x, float __y);
/* Test for signaling NaN.  */
extern int __issignalingf128(float __value);
/* Declare functions returning a narrower type.  */
/* This variable is used by `gamma' and `lgamma'.  */
extern int signgam;
/*
Depending on the type of TG_ARG, call an appropriately suffixed
   version of FUNC with arguments (including parentheses) ARGS.
   Suffixed functions may not exist for long double if it has the same
   format as double, or for other types with the same format as float,
   double or long double.  The behavior is undefined if the argument
   does not have a real floating type.  The definition may use a
   conditional expression, so all suffixed versions of FUNC must
   return the same type (FUNC may include a cast if necessary rather
   than being a single identifier). 
*/
/* ISO C99 defines some generic macros which work on any data type.  */
/* All floating-point numbers can be put in one of these categories.  */
enum test_ua_c_16379 { FP_NAN = 0, FP_INFINITE = 1, FP_ZERO = 2, FP_SUBNORMAL = 3, FP_NORMAL = 4 };
/*
GCC bug 66462 means we cannot use the math builtins with -fsignaling-nan,
   so disable builtins if this is enabled.  When fixed in a newer GCC,
   the __SUPPORT_SNAN__ check may be skipped for those versions. 
*/
/* Return number of classification appropriate for X.  */
/*
The check for __cplusplus allows the use of the builtin, even
	when optimization for size is on.  This is provided for
	libstdc++, only to let its configure test work when it is built
	with -Os.  No further use of this definition of fpclassify is
	expected in C++ mode, since libstdc++ provides its own version
	of fpclassify in cmath (which undefines fpclassify). 
*/
/* Return nonzero value if sign of X is negative.  */
/* Return nonzero value if X is not +-Inf or NaN.  */
/* Return nonzero value if X is neither zero, subnormal, Inf, nor NaN.  */
/*
Return nonzero value if X is a NaN.  We could use `fpclassify' but
   we already have this functions `__isnan' and it is faster. 
*/
/* Return nonzero value if X is positive or negative infinity.  */
/* Bitmasks for the math_errhandling macro.  */
/*
By default all math functions support both errno and exception handling
   (except for soft floating point implementations which may only support
   errno handling).  If errno handling is disabled, exceptions are still
   supported by GLIBC.  Set math_errhandling to 0 with -ffast-math (this is
   nonconforming but it is more useful than leaving it undefined). 
*/
/* Some useful constants.  */
/*
The above constants are not adequate for computation using `long double's.
   Therefore we provide as an extension constants with similar names as a
   GNU extension.  Provide enough digits for the 128-bit IEEE quad. 
*/
/*
ISO C99 defines some macros to compare number while taking care for
   unordered numbers.  Many FPUs provide special instructions to support
   these operations.  Generic support in GCC for these as builtins went
   in 2.97, but not all cpus added their patterns until 3.1.  Therefore
   we enable the builtins from 3.1 onwards and use a generic implementation
   othwerwise. 
*/
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

	ISO C99 Standard: 7.20 General utilities	<stdlib.h>

*/
/*
Handle feature test macros at the start of a header.
   Copyright (C) 2016-2021 Free Software Foundation, Inc.
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
This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included. 
*/
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
ISOIEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro. 
*/
/*
ISOIEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.) 
*/
/*
ISOIEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X. 
*/
/*
ISOIEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro. 
*/
/* Get size_t, wchar_t and NULL from <stddef.h>.  */
/*
Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it andor modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http:www.gnu.org/licenses/>. 
*/
/*

 ISO C Standard:  7.17  Common definitions  <stddef.h>

*/
/*
Any one of these symbols __need_ means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done. 
*/
/*
This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage. 
*/
/*
Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it. 
*/
/*
On VxWorks, <typevxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected. 
*/
/*
In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2. 
*/
/* Signed type of difference of two pointers.  */
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/* Unsigned type of `sizeof' something.  */
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/*
Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character. 
*/
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/*
On BSD386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
   instead of _WCHAR_T_, and _BSD_RUNE_T_ (which, unlike the other
   symbols in the _FOO_T_ family, stays defined even after its
   corresponding type is defined).  If we define wchar_t, then we
   must undef _WCHAR_T_; for BSD/386 1.1 (and perhaps others), if
   we undef _WCHAR_T_, then we must also define rune_t, since 
   headers like runetype.h assume that if machine/ansi.h is included,
   and _BSD_WCHAR_T_ is not defined, then rune_t is available.
   machine/ansi.h says, "Note that _WCHAR_T_ and _RUNE_T_ must be of
   the same type."
*/
/*
FreeBSD 5 can't be handled well using "traditional" logic above
   since it no longer defines _BSD_RUNE_T_ yet still desires to export
   rune_t in some cases...
*/
typedef int wchar_t;
/* A null pointer constant.  */
/* XPG requires a few symbols from <syswait.h> being defined.  */
/*
Definitions of flag bits for `waitpid' et al.
   Copyright (C) 1992-2021 Free Software Foundation, Inc.
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
/* Bits in the third argument to `waitpid'.  */
/* Bits in the fourth argument to `waitid'.  */
/*
Definitions of status bits for `wait' et al.
   Copyright (C) 1992-2021 Free Software Foundation, Inc.
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
/* Everything extant so far uses these same bits.  */
/* If WIFEXITED(STATUS), the low-order 8 bits of the status.  */
/* If WIFSIGNALED(STATUS), the terminating signal.  */
/* If WIFSTOPPED(STATUS), the signal that stopped the child.  */
/* Nonzero if STATUS indicates normal termination.  */
/* Nonzero if STATUS indicates termination by a signal.  */
/* Nonzero if STATUS indicates the child is stopped.  */
/*
Nonzero if STATUS indicates the child continued after a stop.  We only
   define this if <bitswaitflags.h> provides the WCONTINUED flag bit. 
*/
/* Nonzero if STATUS indicates the child dumped core.  */
/* Macros for constructing status values.  */
/* Define the macros <syswait.h> also would define this way.  */
/* _FloatN API tests for enablement.  */
/*
Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
/* Returned by `div'.  */
struct named_test_ua_c_16417
{
	int quot;
	/* Quotient.  */ 
	int rem;
};

/* Remainder.  */
typedef struct named_test_ua_c_16417 div_t;
/* Returned by `ldiv'.  */
struct named_test_ua_c_16436
{
	long int quot;
	/* Quotient.  */ 
	long int rem;
};

/* Remainder.  */
typedef struct named_test_ua_c_16436 ldiv_t;
/* Returned by `lldiv'.  */
struct named_test_ua_c_16460
{
	long long int quot;
	/* Quotient.  */ 
	long long int rem;
};

/* Remainder.  */
typedef struct named_test_ua_c_16460 lldiv_t;
/* The largest number rand will return (same as INT_MAX).  */
/*
We define these the same for all machines.
   Changes from this to the outside world should be done in `_exit'. 
*/
/* Maximum length of a multibyte character in the current locale.  */
extern size_t __ctype_get_mb_cur_max(void );
/* Convert a string to a floating-point number.  */
extern double atof(const char * __nptr);
/* Convert a string to an integer.  */
extern int atoi(const char * __nptr);
/* Convert a string to a long integer.  */
extern long int atol(const char * __nptr);
/* Convert a string to a long long integer.  */
extern long long int atoll(const char * __nptr);
/* Convert a string to a floating-point number.  */
extern double strtod(const char * __nptr, char * * __endptr);
/* Likewise for `float' and `long double' sizes of floating-point numbers.  */
extern float strtof(const char * __nptr, char * * __endptr);
extern long double strtold(const char * __nptr, char * * __endptr);
/* Likewise for '_FloatN' and '_FloatNx'.  */
/* Convert a string to a long integer.  */
extern long int strtol(const char * __nptr, char * * __endptr, int __base);
/* Convert a string to an unsigned long integer.  */
extern unsigned long int strtoul(const char * __nptr, char * * __endptr, int __base);
/* Convert a string to a quadword integer.  */
extern long long int strtoq(const char * __nptr, char * * __endptr, int __base);
/* Convert a string to an unsigned quadword integer.  */
extern unsigned long long int strtouq(const char * __nptr, char * * __endptr, int __base);
/* Convert a string to a quadword integer.  */
extern long long int strtoll(const char * __nptr, char * * __endptr, int __base);
/* Convert a string to an unsigned quadword integer.  */
extern unsigned long long int strtoull(const char * __nptr, char * * __endptr, int __base);
/* Convert a floating-point number to a string.  */
/*
Convert N to base 64 using the digits ".0-9A-Za-z", least-significant
   digit first.  Returns a pointer to static storage overwritten by the
   next call. 
*/
extern char *l64a(long int __n);
/* Read a number from a string S in base 64 as above.  */
extern long int a64l(const char * __s);
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

	POSIX Standard: 2.6 Primitive System Data Types	<sys/types.h>

*/
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
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/* Returned by `clock'.  */
typedef __clock_t clock_t;
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/* Clock ID used in clock and timer functions.  */
typedef __clockid_t clockid_t;
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/* Returned by `time'.  */
typedef __time_t time_t;
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/* Timer ID returned by `timer_create'.  */
typedef __timer_t timer_t;
/*
Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it andor modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http:www.gnu.org/licenses/>. 
*/
/*

 ISO C Standard:  7.17  Common definitions  <stddef.h>

*/
/*
Any one of these symbols __need_ means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done. 
*/
/*
This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage. 
*/
/*
Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it. 
*/
/*
On VxWorks, <typevxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected. 
*/
/*
In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2. 
*/
/* Signed type of difference of two pointers.  */
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/* Unsigned type of `sizeof' something.  */
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/*
Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character. 
*/
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/* A null pointer constant.  */
/* Old compatibility names for C types.  */
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
/* These size-specific names are used by some of the inet code.  */
/*
Define intN_t types.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
/* These were defined by ISO C without the first `_'.  */
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t;
/*
Some code from BIND tests this macro to see if the types above are
   defined. 
*/
/* In BSD <systypes.h> is expected to define BYTE_ORDER.  */
/*
Copyright (C) 1992-2021 Free Software Foundation, Inc.
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
/* Get the definitions of ___ENDIAN, __BYTE_ORDER, and __FLOAT_WORD_ORDER.  */
/*
Endian macros for string.h functions
   Copyright (C) 1992-2021 Free Software Foundation, Inc.
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
   <http:www.gnu.org/licenses/>. 
*/
/*
Definitions for byte order, according to significance of bytes,
   from low addresses to high addresses.  The value is what you get by
   putting '4' in the most significant byte, '3' in the second most
   significant byte, '2' in the second least significant byte, and '1'
   in the least significant byte, and then writing down one digit for
   each byte, starting with the byte at the lowest address at the left,
   and proceeding to the byte with the highest address at the right. 
*/
/* This file defines `__BYTE_ORDER' for the particular machine.  */
/* i386x86_64 are little-endian.  */
/*
Some machines may need to use a different endianness for floating point
   values. 
*/
/* Conversion interfaces.  */
/*
Macros and inline functions to swap the order of bytes in integer values.
   Copyright (C) 1997-2021 Free Software Foundation, Inc.
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
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/* Swap bytes in 16-bit value.  */
static inline __uint16_t __bswap_16(__uint16_t __bsx)
{
	__uint16_t _ret_val_0;
	_ret_val_0=__builtin_bswap16(__bsx);
	return _ret_val_0;
}

/* Swap bytes in 32-bit value.  */
static inline __uint32_t __bswap_32(__uint32_t __bsx)
{
	__uint32_t _ret_val_0;
	_ret_val_0=__builtin_bswap32(__bsx);
	return _ret_val_0;
}

/* Swap bytes in 64-bit value.  */
static inline __uint64_t __bswap_64(__uint64_t __bsx)
{
	__uint64_t _ret_val_0;
	_ret_val_0=__builtin_bswap64(__bsx);
	return _ret_val_0;
}

/*
Inline functions to return unsigned integer values unchanged.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/*
These inline functions are to ensure the appropriate type
   conversions and associated diagnostics from macros that convert to
   a given endianness. 
*/
static inline __uint16_t __uint16_identity(__uint16_t __x)
{
	return __x;
}

static inline __uint32_t __uint32_identity(__uint32_t __x)
{
	return __x;
}

static inline __uint64_t __uint64_identity(__uint64_t __x)
{
	return __x;
}

/* It also defines `fd_set' and the FD_ macros for `select'.  */
/*
`fd_set' type and related macros, and `select'`pselect' declarations.
   Copyright (C) 1996-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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
/* 	POSIX 1003.1g: 6.2 Select from File Descriptor Sets <sysselect.h>  */
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
/* Get definition of needed basic types.  */
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/* Get __FD_ definitions.  */
/*
Copyright (C) 1997-2021 Free Software Foundation, Inc.
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
We don't use `memset' because this would require a prototype and
   the array isn't too big. 
*/
/* Get sigset_t.  */
struct named_test_ua_c_17666
{
	unsigned long int __val[(1024/(8*sizeof (unsigned long int)))];
};

typedef struct named_test_ua_c_17666 __sigset_t;
/* A set of signals to be blocked, unblocked, or waited for.  */
typedef __sigset_t sigset_t;
/* Get definition of timer specification structures.  */
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/*
A time value that is accurate to the nearest
   microsecond but also has a range of years. 
*/
struct timeval
{
	__time_t tv_sec;
	/* Seconds.  */ 
	__suseconds_t tv_usec;
};

/* Microseconds.  */
/* NB: Include guard matches what <linuxtime.h> uses.  */
/*
bitstypes.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
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

 Never include this file directly; use <sys/types.h> instead.

*/
/*
Endian macros for string.h functions
   Copyright (C) 1992-2021 Free Software Foundation, Inc.
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
   <http:www.gnu.org/licenses/>. 
*/
/*
POSIX.1b structure for a time value.  This is like a `struct timeval' but
   has nanoseconds instead of microseconds. 
*/
struct timespec
{
	__time_t tv_sec;
	/* Seconds.  */ 
	__syscall_slong_t tv_nsec;
};

/* Nanoseconds.  */
typedef __suseconds_t suseconds_t;
/* The fd_set member is required to be an array of longs.  */
typedef long int __fd_mask;
/* Some versions of <linuxposix_types.h> define this macros.  */
/* It's easier to assume 8-bit bytes than to get CHAR_BIT.  */
/* fd_set for select and pselect.  */
struct named_test_ua_c_17761
{
	/* XPG4.2 requires this member name.  Otherwise avoid the name
	       from the global namespace.  */ 
	__fd_mask __fds_bits[(1024/(8*((int)sizeof (__fd_mask))))];
};

typedef struct named_test_ua_c_17761 fd_set;
/* Maximum number of file descriptors in `fd_set'.  */
/* Sometimes the fd_set member is assumed to have this type.  */
typedef __fd_mask fd_mask;
/* Number of bits per word of `fd_set' (some code assumes this is 32).  */
/* Access macros for `fd_set'.  */
/*
Check the first NFDS descriptors each in READFDS (if not NULL) for read
   readiness, in WRITEFDS (if not NULL) for write readiness, and in EXCEPTFDS
   (if not NULL) for exceptional conditions.  If TIMEOUT is not NULL, time out
   after waiting the interval specified therein.  Returns the number of ready
   descriptors, or -1 for errors.

   This function is a cancellation point and therefore not marked with
   __THROW. 
*/
extern int select(int __nfds, fd_set * __readfds, fd_set * __writefds, fd_set * __exceptfds, struct timeval * __timeout);
/*
Same as above only that the TIMEOUT value is given with higher
   resolution and a sigmask which is been set temporarily.  This version
   should be used.

   This function is a cancellation point and therefore not marked with
   __THROW. 
*/
extern int pselect(int __nfds, fd_set * __readfds, fd_set * __writefds, fd_set * __exceptfds, const struct timespec * __timeout, const __sigset_t * __sigmask);
/* Define some inlines helping to catch common problems.  */
typedef __blksize_t blksize_t;
/* Types from the Large File Support interface.  */
typedef __blkcnt_t blkcnt_t;
/* Type to count number of disk blocks.  */
typedef __fsblkcnt_t fsblkcnt_t;
/* Type to count file system blocks.  */
typedef __fsfilcnt_t fsfilcnt_t;
/* Type to count file system inodes.  */
/* Now add the thread types.  */
/*
Declaration of common pthread types for all architectures.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
/* For internal mutex and condition variable definitions.  */
/*
Common threading primitives definitions for both POSIX and C11.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
Arch-specific definitions.  Each architecture must define the following
   macros to define the expected sizes of pthread data types:

   __SIZEOF_PTHREAD_ATTR_T        - size of pthread_attr_t.
   __SIZEOF_PTHREAD_MUTEX_T       - size of pthread_mutex_t.
   __SIZEOF_PTHREAD_MUTEXATTR_T   - size of pthread_mutexattr_t.
   __SIZEOF_PTHREAD_COND_T        - size of pthread_cond_t.
   __SIZEOF_PTHREAD_CONDATTR_T    - size of pthread_condattr_t.
   __SIZEOF_PTHREAD_RWLOCK_T      - size of pthread_rwlock_t.
   __SIZEOF_PTHREAD_RWLOCKATTR_T  - size of pthread_rwlockattr_t.
   __SIZEOF_PTHREAD_BARRIER_T     - size of pthread_barrier_t.
   __SIZEOF_PTHREAD_BARRIERATTR_T - size of pthread_barrierattr_t.

   The additional macro defines any constraint for the lock alignment
   inside the thread structures:

   __LOCK_ALIGNMENT - for internal lockfutex usage.

   Same idea but for the once locking primitive:

   __ONCE_ALIGNMENT - for pthread_once_t/once_flag definition. 
*/
/*
Copyright (C) 2002-2021 Free Software Foundation, Inc.
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
/* Determine the wordsize from the preprocessor defines.  */
/* Both x86-64 and x32 use the 64-bit system call interface.  */
/* Common definition of pthread_mutex_t. */
struct __pthread_internal_list
{
	struct __pthread_internal_list * __prev;
	struct __pthread_internal_list * __next;
};

typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_internal_slist
{
	struct __pthread_internal_slist * __next;
};

typedef struct __pthread_internal_slist __pthread_slist_t;
/*
Arch-specific mutex definitions.  A generic implementation is provided
   by sysdepsnptl/bits/struct_mutex.h.  If required, an architecture
   can override it by defining:

   1. struct __pthread_mutex_s (used on both pthread_mutex_t and mtx_t
      definition).  It should contains at least the internal members
      defined in the generic version.

   2. __LOCK_ALIGNMENT for any extra attribute for internal lock used with
      atomic operations.

   3. The macro __PTHREAD_MUTEX_INITIALIZER used for static initialization.
      It should initialize the mutex internal flag. 
*/
/*
x86 internal mutex struct definitions.
   Copyright (C) 2019-2021 Free Software Foundation, Inc.
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
   <http:www.gnu.org/licenses/>. 
*/
struct __pthread_mutex_s
{
	int __lock;
	unsigned int __count;
	int __owner;
	unsigned int __nusers;
	/* KIND must stay at this position in the structure to maintain
	     binary compatibility with static initializers.  */ 
	int __kind;
	short __spins;
	short __elision;
	__pthread_list_t __list;
};

/*
Arch-sepecific read-write lock definitions.  A generic implementation is
   provided by struct_rwlock.h.  If required, an architecture can override it
   by defining:

   1. struct __pthread_rwlock_arch_t (used on pthread_rwlock_t definition).
      It should contain at least the internal members defined in the
      generic version.

   2. The macro __PTHREAD_RWLOCK_INITIALIZER used for static initialization.
      It should initialize the rwlock internal type. 
*/
/*
x86 internal rwlock struct definitions.
   Copyright (C) 2019-2021 Free Software Foundation, Inc.

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
   <http:www.gnu.org/licenses/>. 
*/
struct __pthread_rwlock_arch_t
{
	unsigned int __readers;
	unsigned int __writers;
	unsigned int __wrphase_futex;
	unsigned int __writers_futex;
	unsigned int __pad3;
	unsigned int __pad4;
	int __cur_writer;
	int __shared;
	signed char __rwelision;
	unsigned char __pad1[7];
	unsigned long int __pad2;
	/* FLAGS must stay at this position in the structure to maintain
	     binary compatibility.  */ 
	unsigned int __flags;
};

/* Common definition of pthread_cond_t. */
struct named_test_ua_c_18133
{
	unsigned int __low;
	unsigned int __high;
};

union named_test_ua_c_18118
{
	unsigned long long int __wseq;
	struct named_test_ua_c_18133 __wseq32;
};

struct named_test_ua_c_18172
{
	unsigned int __low;
	unsigned int __high;
};

union named_test_ua_c_18157
{
	unsigned long long int __g1_start;
	struct named_test_ua_c_18172 __g1_start32;
};

struct __pthread_cond_s
{
	union named_test_ua_c_18118 ;
	union named_test_ua_c_18157 ;
	unsigned int __g_refs[2];
	unsigned int __g_size[2];
	unsigned int __g1_orig_size;
	unsigned int __wrefs;
	unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
struct named_test_ua_c_18263
{
	int __data;
};

typedef struct named_test_ua_c_18263 __once_flag;
/*
Thread identifiers.  The structure of the attribute type is not
   exposed on purpose. 
*/
typedef unsigned long int pthread_t;
/*
Data structures for mutex handling.  The structure of the attribute
   type is not exposed on purpose. 
*/
union named_test_ua_c_18288
{
	char __size[4];
	int __align;
};

typedef union named_test_ua_c_18288 pthread_mutexattr_t;
/*
Data structure for condition variable handling.  The structure of
   the attribute type is not exposed on purpose. 
*/
union named_test_ua_c_18310
{
	char __size[4];
	int __align;
};

typedef union named_test_ua_c_18310 pthread_condattr_t;
/* Keys for thread-specific data */
typedef unsigned int pthread_key_t;
/* Once-only execution */
typedef int pthread_once_t;
union pthread_attr_t
{
	char __size[56];
	long int __align;
};

typedef union pthread_attr_t pthread_attr_t;
union named_test_ua_c_18379
{
	struct __pthread_mutex_s __data;
	char __size[40];
	long int __align;
};

typedef union named_test_ua_c_18379 pthread_mutex_t;
union named_test_ua_c_18410
{
	struct __pthread_cond_s __data;
	char __size[48];
	long long int __align;
};

typedef union named_test_ua_c_18410 pthread_cond_t;
/*
Data structure for reader-writer lock variable handling.  The
   structure of the attribute type is deliberately not exposed. 
*/
union named_test_ua_c_18444
{
	struct __pthread_rwlock_arch_t __data;
	char __size[56];
	long int __align;
};

typedef union named_test_ua_c_18444 pthread_rwlock_t;
union named_test_ua_c_18475
{
	char __size[8];
	long int __align;
};

typedef union named_test_ua_c_18475 pthread_rwlockattr_t;
/* POSIX spinlock data type.  */
typedef volatile int pthread_spinlock_t;
/*
POSIX barriers data type.  The structure of the type is
   deliberately not exposed. 
*/
union named_test_ua_c_18508
{
	char __size[32];
	long int __align;
};

typedef union named_test_ua_c_18508 pthread_barrier_t;
union named_test_ua_c_18532
{
	char __size[4];
	int __align;
};

typedef union named_test_ua_c_18532 pthread_barrierattr_t;
/*
These are the functions that actually do things.  The `random', `srandom',
   `initstate' and `setstate' functions are those from BSD Unices.
   The `rand' and `srand' functions are required by the ANSI standard.
   We provide both interfaces to the same random number generator. 
*/
/* Return a random long integer between 0 and 2^31-1 inclusive.  */
extern long int random(void );
/* Seed the random number generator with the given number.  */
extern void srandom(unsigned int __seed);
/*
Initialize the random number generator to use state buffer STATEBUF,
   of length STATELEN, and seed it with SEED.  Optimal lengths are 8, 16,
   32, 64, 128 and 256, the bigger the better; values less than 8 will
   cause an error and values greater than 256 will be rounded down. 
*/
extern char *initstate(unsigned int __seed, char * __statebuf, size_t __statelen);
/*
Switch the random number generator to state buffer STATEBUF,
   which should have been previously initialized by `initstate'. 
*/
extern char *setstate(char * __statebuf);
/*
Reentrant versions of the `random' family of functions.
   These functions all use the following data structure to contain
   state, rather than global state variables. 
*/
struct random_data
{
	int32_t * fptr;
	/* Front pointer.  */ 
	int32_t * rptr;
	/* Rear pointer.  */ 
	int32_t * state;
	/* Array of state values.  */ 
	int rand_type;
	/* Type of random number generator.  */ 
	int rand_deg;
	/* Degree of random number generator.  */ 
	int rand_sep;
	/* Distance between front and rear.  */ 
	int32_t * end_ptr;
};

/* Pointer behind state table.  */
extern int random_r(struct random_data * __buf, int32_t * __result);
extern int srandom_r(unsigned int __seed, struct random_data * __buf);
extern int initstate_r(unsigned int __seed, char * __statebuf, size_t __statelen, struct random_data * __buf);
extern int setstate_r(char * __statebuf, struct random_data * __buf);
/* Return a random integer between 0 and RAND_MAX inclusive.  */
extern int rand(void );
/* Seed the random number generator with the given number.  */
extern void srand(unsigned int __seed);
/* Reentrant interface according to POSIX.1.  */
extern int rand_r(unsigned int * __seed);
/* System V style 48-bit random number generator functions.  */
/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */
extern double drand48(void );
extern double erand48(unsigned short int __xsubi[3]);
/* Return non-negative, long integer in [0,2^31).  */
extern long int lrand48(void );
extern long int nrand48(unsigned short int __xsubi[3]);
/* Return signed, long integers in [-2^31,2^31).  */
extern long int mrand48(void );
extern long int jrand48(unsigned short int __xsubi[3]);
/* Seed random number generator.  */
extern void srand48(long int __seedval);
extern unsigned short int *seed48(unsigned short int __seed16v[3]);
extern void lcong48(unsigned short int __param[7]);
/*
Data structure for communication with thread safe versions.  This
   type is to be regarded as opaque.  It's only exported because users
   have to allocate objects of this type. 
*/
struct drand48_data
{
	unsigned short int __x[3];
	/* Current state.  */ 
	unsigned short int __old_x[3];
	/* Old state.  */ 
	unsigned short int __c;
	/* Additive const. in congruential formula.  */ 
	unsigned short int __init;
	/* Flag for initializing.  */ 
	unsigned long long int __a;
};

/*
Factor in congruential
						   formula. 
*/
/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */
extern int drand48_r(struct drand48_data * __buffer, double * __result);
extern int erand48_r(unsigned short int __xsubi[3], struct drand48_data * __buffer, double * __result);
/* Return non-negative, long integer in [0,2^31).  */
extern int lrand48_r(struct drand48_data * __buffer, long int * __result);
extern int nrand48_r(unsigned short int __xsubi[3], struct drand48_data * __buffer, long int * __result);
/* Return signed, long integers in [-2^31,2^31).  */
extern int mrand48_r(struct drand48_data * __buffer, long int * __result);
extern int jrand48_r(unsigned short int __xsubi[3], struct drand48_data * __buffer, long int * __result);
/* Seed random number generator.  */
extern int srand48_r(long int __seedval, struct drand48_data * __buffer);
extern int seed48_r(unsigned short int __seed16v[3], struct drand48_data * __buffer);
extern int lcong48_r(unsigned short int __param[7], struct drand48_data * __buffer);
/* Allocate SIZE bytes of memory.  */
extern void *malloc(size_t __size);
/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
extern void *calloc(size_t __nmemb, size_t __size);
/*
Re-allocate the previously allocated block
   in PTR, making the new block SIZE bytes long. 
*/
/*
__attribute_malloc__ is not used, because if realloc returns
   the same pointer that was passed to it, aliasing needs to be allowed
   between objects pointed by the old and new pointers. 
*/
extern void *realloc(void * __ptr, size_t __size);
/* Free a block allocated by `malloc', `realloc' or `calloc'.  */
extern void free(void * __ptr);
/*
Re-allocate the previously allocated block in PTR, making the new
   block large enough for NMEMB elements of SIZE bytes each. 
*/
/*
__attribute_malloc__ is not used, because if reallocarray returns
   the same pointer that was passed to it, aliasing needs to be allowed
   between objects pointed by the old and new pointers. 
*/
extern void *reallocarray(void * __ptr, size_t __nmemb, size_t __size);
/* Add reallocarray as its own deallocator.  */
extern void *reallocarray(void * __ptr, size_t __nmemb, size_t __size);
/*
Copyright (C) 1992-2021 Free Software Foundation, Inc.
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
Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it andor modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http:www.gnu.org/licenses/>. 
*/
/*

 ISO C Standard:  7.17  Common definitions  <stddef.h>

*/
/*
Any one of these symbols __need_ means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done. 
*/
/*
This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage. 
*/
/*
Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it. 
*/
/*
On VxWorks, <typevxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected. 
*/
/*
In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2. 
*/
/* Signed type of difference of two pointers.  */
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/* Unsigned type of `sizeof' something.  */
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/*
Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character. 
*/
/*
Define this type if we are doing the whole job,
   or if we want this type in particular. 
*/
/* A null pointer constant.  */
/* Remove any previous definition.  */
/* Allocate a block that will be freed when the calling function exits.  */
extern void *alloca(size_t __size);
/* Allocate SIZE bytes on a page boundary.  The storage cannot be freed.  */
extern void *valloc(size_t __size);
/* Allocate memory of SIZE bytes with an alignment of ALIGNMENT.  */
extern int posix_memalign(void * * __memptr, size_t __alignment, size_t __size);
/* ISO C variant of aligned allocation.  */
extern void *aligned_alloc(size_t __alignment, size_t __size);
/* Abort execution and generate a core-dump.  */
extern void abort(void );
/* Register a function to be called when `exit' is called.  */
extern int atexit(void (* __func)(void ));
/* Register a function to be called when `quick_exit' is called.  */
extern int at_quick_exit(void (* __func)(void ));
/*
Register a function to be called with the status
   given to `exit' and the given argument. 
*/
extern int on_exit(void (* __func)(int __status, void * __arg), void * __arg);
/*
Call all functions registered with `atexit' and `on_exit',
   in the reverse of the order in which they were registered,
   perform stdio cleanup, and terminate program execution with STATUS. 
*/
extern void exit(int __status);
/*
Call all functions registered with `at_quick_exit' in the reverse
   of the order in which they were registered and terminate program
   execution with STATUS. 
*/
extern void quick_exit(int __status);
/*
Terminate the program with STATUS without calling any of the
   functions registered with `atexit' or `on_exit'. 
*/
extern void _Exit(int __status);
/* Return the value of envariable NAME, or NULL if it doesn't exist.  */
extern char *getenv(const char * __name);
/* The SVID says this is in <stdio.h>, but this seems a better place.	 */
/*
Put STRING, which is of the form "NAME=VALUE", in the environment.
   If there is no `=', remove NAME from the environment. 
*/
extern int putenv(char * __string);
/*
Set NAME to VALUE in the environment.
   If REPLACE is nonzero, overwrite an existing value. 
*/
extern int setenv(const char * __name, const char * __value, int __replace);
/* Remove the variable NAME from the environment.  */
extern int unsetenv(const char * __name);
/*
The `clearenv' was planned to be added to POSIX.1 but probably
   never made it.  Nevertheless the POSIX.9 standard (POSIX bindings
   for Fortran 77) requires this function. 
*/
extern int clearenv(void );
/*
Generate a unique temporary file name from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the file name unique.
   Always returns TEMPLATE, it's either a temporary file name or a null
   string if it cannot get a unique file name. 
*/
extern char *mktemp(char * __template);
/*
Generate a unique temporary file name from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the filename unique.
   Returns a file descriptor open on the file for reading and writing,
   or -1 if it cannot create a uniquely-named file.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int mkstemp(char * __template);
/*
Similar to mkstemp, but the template can have a suffix after the
   XXXXXX.  The length of the suffix is specified in the second
   parameter.

   This function is a possible cancellation point and therefore not
   marked with __THROW. 
*/
extern int mkstemps(char * __template, int __suffixlen);
/*
Create a unique temporary directory from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the directory name unique.
   Returns TEMPLATE, or a null pointer if it cannot get a unique name.
   The directory is created mode 700. 
*/
extern char *mkdtemp(char * __template);
/*
Execute the given line as a shell command.

   This function is a cancellation point and therefore not marked with
   __THROW. 
*/
extern int system(const char * __command);
/*
Return the canonical absolute name of file NAME.  If RESOLVED is
   null, the result is malloc'd; otherwise, if the canonical name is
   PATH_MAX chars or more, returns null with `errno' set to
   ENAMETOOLONG; if the name fits in fewer than PATH_MAX chars,
   returns the name in RESOLVED. 
*/
extern char *realpath(const char * __name, char * __resolved);
/* Shorthand for type of comparison functions.  */
typedef int (* __compar_fn_t)(const void * , const void * );
/*
Do a binary search for KEY in BASE, which consists of NMEMB elements
   of SIZE bytes each, using COMPAR to perform the comparisons. 
*/
extern void *bsearch(const void * __key, const void * __base, size_t __nmemb, size_t __size, __compar_fn_t __compar);
/*
Sort NMEMB elements of BASE, of SIZE bytes each,
   using COMPAR to perform the comparisons. 
*/
extern void qsort(void * __base, size_t __nmemb, size_t __size, __compar_fn_t __compar);
/* Return the absolute value of X.  */
extern int abs(int __x);
extern long int labs(long int __x);
extern long long int llabs(long long int __x);
/*
Return the `div_t', `ldiv_t' or `lldiv_t' representation
   of the value of NUMER over DENOM.
*/
/* GCC may have built-ins for these someday.  */
extern div_t div(int __numer, int __denom);
extern ldiv_t ldiv(long int __numer, long int __denom);
extern lldiv_t lldiv(long long int __numer, long long int __denom);
/*
Convert floating point numbers to strings.  The returned values are
   valid only until another call to the same function. 
*/
/*
Convert VALUE to a string with NDIGIT digits and return a pointer to
   this.  SetDECPT with the position of the decimal character and *SIGN
   with the sign of the number. 
*/
extern char *ecvt(double __value, int __ndigit, int * __decpt, int * __sign);
/*
Convert VALUE to a string rounded to NDIGIT decimal digits.  SetDECPT
   with the position of the decimal character and *SIGN with the sign of
   the number. 
*/
extern char *fcvt(double __value, int __ndigit, int * __decpt, int * __sign);
/*
If possible convert VALUE to a string with NDIGIT significant digits.
   Otherwise use exponential representation.  The resulting string will
   be written to BUF. 
*/
extern char *gcvt(double __value, int __ndigit, char * __buf);
/* Long double versions of above functions.  */
extern char *qecvt(long double __value, int __ndigit, int * __decpt, int * __sign);
extern char *qfcvt(long double __value, int __ndigit, int * __decpt, int * __sign);
extern char *qgcvt(long double __value, int __ndigit, char * __buf);
/*
Reentrant version of the functions above which provide their own
   buffers. 
*/
extern int ecvt_r(double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len);
extern int fcvt_r(double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len);
extern int qecvt_r(long double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len);
extern int qfcvt_r(long double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len);
/*
Return the length of the multibyte character
   in S, which is no longer than N. 
*/
extern int mblen(const char * __s, size_t __n);
/*
Return the length of the given multibyte character,
   putting its `wchar_t' representation inPWC. 
*/
extern int mbtowc(wchar_t * __pwc, const char * __s, size_t __n);
/*
Put the multibyte character represented
   by WCHAR in S, returning its length. 
*/
extern int wctomb(char * __s, wchar_t __wchar);
/* Convert a multibyte string to a wide char string.  */
extern size_t mbstowcs(wchar_t * __pwcs, const char * __s, size_t __n);
/* Convert a wide char string to multibyte string.  */
extern size_t wcstombs(char * __s, const wchar_t * __pwcs, size_t __n);
/*
Determine whether the string value of RESPONSE matches the affirmation
   or negative response expression as specified by the LC_MESSAGES category
   in the program's current locale.  Returns 1 if affirmative, 0 if
   negative, and -1 if not matching. 
*/
extern int rpmatch(const char * __response);
/*
Parse comma separated suboption fromOPTIONP and match against
   strings in TOKENS.  If found return index and set *VALUEP to
   optional value introduced by an equal sign.  If the suboption is
   not part of TOKENS return in *VALUEP beginning of unknown
   suboption.  On exit *OPTIONP is set to the beginning of the next
   token or at the terminating NUL character. 
*/
extern int getsubopt(char * * __optionp, char * const * __tokens, char * * __valuep);
/* XOpen pseudo terminal handling.  */
/*
Put the 1 minute, 5 minute and 15 minute load averages into the first
   NELEM elements of LOADAVG.  Return the number written (never more than
   three, but may be less than NELEM), or -1 if an error occurred. 
*/
extern int getloadavg(double __loadavg[], int __nelem);
/*
Floating-point inline functions for stdlib.h.
   Copyright (C) 2012-2021 Free Software Foundation, Inc.
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
/* Define some macros helping to catch buffer overflows.  */
/*
Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
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
/* ------------------------------------------------------------------------- */
/*                                                                          */
/*  This benchmark is an OpenMP C version of the NPB UA code. This OpenMP   */
/*  C version is developed by the Center for Manycore Programming at Seoul  */
/*  National University and derived from the OpenMP Fortran versions in     */
/*  "NPB3.3-OMP" developed by NAS.                                          */
/*                                                                          */
/*  Permission to use, copy, distribute and modify this software for any    */
/*  purpose with or without fee is hereby granted. This software is         */
/*  provided "as is" without express or implied warranty.                   */
/*                                                                          */
/*  Information on NPB 3.3, including the technical report, the original    */
/*  specifications, source code, results and information on how to submit   */
/*  new results, is available at:                                           */
/*                                                                          */
/*           http:www.nas.nasa.govSoftware/NPB/                          */
/*                                                                          */
/*  Send comments or suggestions for this OpenMP C version to               */
/*  cmp@aces.snu.ac.kr                                                      */
/*                                                                          */
/*          Center for Manycore Programming                                 */
/*          School of Computer Science and Engineering                      */
/*          Seoul National University                                       */
/*          Seoul 151-744, Korea                                            */
/*                                                                          */
/*          E-mail:  cmp@aces.snu.ac.kr                                     */
/*                                                                          */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* Authors: Sangmin Seo, Jungwon Kim, Jun Lee, Jeongho Nah, Gangwon Jo,     */
/*          and Jaejin Lee                                                  */
/* ------------------------------------------------------------------------- */
/* Array dimensions      */
/* commonusrdati */
extern int fre, niter, nmxh;
/* commonusrdatr */
extern double alpha, dlmin, dtime;
/* commondimn */
extern int nelt, ntot, nmor, nvertex;
/* commonbench1 */
extern double x0, _y0, z0, time;
/* double arrays associated with collocation points */
/* commoncolldp */
extern double ta1[8800][5][5][5];
extern double ta2[8800][5][5][5];
extern double trhs[8800][5][5][5];
extern double t[8800][5][5][5];
extern double tmult[8800][5][5][5];
extern double dpcelm[8800][5][5][5];
extern double pdiff[8800][5][5][5];
extern double pdiffp[8800][5][5][5];
/* double arrays associated with mortar points */
/* commonmortdp */
extern double umor[334600];
extern double mormult[334600];
extern double tmort[334600];
extern double tmmor[334600];
extern double rmor[334600];
extern double dpcmor[334600];
extern double pmorx[334600];
extern double ppmor[334600];
/* integer arrays associated with element faces */
/* commonfacein */
extern int idmo[8800][6][2][2][5][5];
extern int idel[8800][6][5][5];
extern int sje[8800][6][2][2];
extern int sje_new[8800][6][2][2];
extern int ijel[8800][6][2];
extern int ijel_new[8800][6][2];
extern int cbc[8800][6];
/*  */
extern int cbc_new[8800][6];
/*  */
/* integer array associated with vertices */
/* commonvin */
extern int vassign[8800][8];
extern int emo[(8*8800)][8][2];
extern int nemo[(8*8800)];
/* integer array associated with element edges */
/* commonedgein */
extern int diagn[8800][12][2];
/* integer arrays associated with elements */
/* commoneltin */
extern int tree[8800];
extern int treenew[8800];
extern int mt_to_id[8800];
extern int mt_to_id_old[8800];
extern int id_to_mt[8800];
extern int newc[8800];
/*  */
extern int newi[8800];
/*  */
extern int newe[8800];
/*  */
extern int ref_front_id[8800];
/*  */
extern int ich[8800];
/*  */
extern int size_e[8800];
extern int front[8800];
extern int action[8800];
/* small arrays */
/* commontransr */
extern double qbnew[2][5][(5-2)];
extern double bqnew[2][(5-2)][(5-2)];
/* gauss-labotto and gauss points */
/* commongauss */
extern double zgm1[5];
/* weights */
/* commonwxyz */
extern double wxm1[5];
extern double w3m1[5][5][5];
/* coordinate of element vertices */
/* commoncoord */
extern double xc[8800][8];
extern double yc[8800][8];
extern double zc[8800][8];
extern double xc_new[8800][8];
extern double yc_new[8800][8];
extern double zc_new[8800][8];
/* dertivative matrices ddr */
/* commondxyz */
extern double dxm1[5][5];
extern double dxtm1[5][5];
extern double wdtdr[5][5];
/* interpolation operators */
/* commonixyz */
extern double ixm31[((5*2)-1)][5];
extern double ixtm31[5][((5*2)-1)];
extern double ixmc1[5][5];
extern double ixtmc1[5][5];
extern double ixmc2[5][5];
extern double ixtmc2[5][5];
extern double map2[5];
extern double map4[5];
/* collocation location within an element */
/* commonxfracs */
extern double xfrac[5];
/* We store some tables of useful topological constants */
/* These constants are intialized in a block data 'top_constants' */
/* commontop_consts */
extern int f_e_ef[6][4];
extern int e_c[8][3];
extern int local_corner[6][8];
extern int cal_nnb[8][3];
extern int oplc[4];
extern int cal_iijj[4][2];
extern int cal_intempx[6][4];
extern int c_f[6][4];
extern int le_arr[3][2][4];
extern int jjface[6];
extern int e_face2[6][4];
extern int op[4];
extern int localedgenumber[12][6];
extern int edgenumber[6][4];
extern int f_c[8][3];
extern int e1v1[6][6];
extern int e2v1[6][6];
extern int e1v2[6][6];
extern int e2v2[6][6];
extern int children[6][4];
extern int iijj[4][2];
extern int v_end[2];
extern int face_l1[3];
extern int face_l2[3];
extern int face_ld[3];
/* Timer parameters */
/* commontiming */
/* Locks used for atomic updates */
/* commonsync_cmn */
void r_init(double a[], int n, double _const);
int main()
{
	double tmp[2][5][5];
	double tmor[8800], tx[8800];
	int ig1, ig2, ig3, ig4, ie, iface, il1, il2, il3, il4;
	int nnje, ije1, ije2, col, i, j, ig, il;
	int k;
	int i, j, k, ntemp, temp, dtemp, temp1, temp2;
	int g1m1_s[6][5][5][5];
	int g4m1_s[6][5][5][5];
	int isize;
	int x;
	int y;
	int z;
	int _ret_val_0;
	int i_0;
	int i_1;
	int col_0;
	int i_2;
	int i_3;
	int col_1;
	int i_4;
	int i_5;
	int i_6;
	int i_7;
	int i_8;
	int i_9;
	int i_10;
	int i_11;
	int i_12;
	v_end[0]=0;
	v_end[1]=(5-1);
	#pragma cetus private(i) 
	#pragma loop name main#0 
	#pragma cetus parallel 
	/*
	Disabled due to low profitability: #pragma omp parallel for private(i)
	*/
	for (i=0; i<5; i ++ )
	{
		xfrac[i]=((zgm1[i]*0.5)+0.5);
	}
	#pragma cetus private(dtemp, i, isize, j, k, temp, temp1, temp2) 
	#pragma loop name main#1 
	#pragma cetus parallel 
	/*
	Disabled due to low profitability: #pragma omp parallel for private(dtemp, i, isize, j, k, temp, temp1, temp2)
	*/
	for (isize=0; isize<6; isize ++ )
	{
		temp=pow(2.0, ( - isize)-2);
		dtemp=(1.0/temp);
		temp1=((temp*temp)*temp);
		temp2=(temp*temp);
		#pragma cetus private(i, j, k) 
		#pragma loop name main#1#0 
		for (k=0; k<5; k ++ )
		{
			#pragma cetus private(i, j) 
			#pragma loop name main#1#0#0 
			for (j=0; j<5; j ++ )
			{
				#pragma cetus private(i) 
				#pragma loop name main#1#0#0#0 
				for (i=0; i<5; i ++ )
				{
					g1m1_s[isize][k][j][i]=(g1m1_s[isize][k][j][i]/wxm1[i]);
					g4m1_s[isize][k][j][i]=(g1m1_s[isize][k][j][i]/wxm1[i]);
				}
			}
		}
	}
	#pragma cetus private(i, j, k, ntemp) 
	#pragma loop name main#2 
	#pragma cetus parallel 
	#pragma omp parallel for private(i, j, k, ntemp)
	for (k=0; k<8800; k ++ )
	{
		ntemp=(((k*5)*5)*5);
		#pragma cetus private(i, j) 
		#pragma loop name main#2#0 
		for (j=0; j<5; j ++ )
		{
			#pragma cetus private(i) 
			#pragma loop name main#2#0#0 
			for (i=0; i<5; i ++ )
			{
				idel[k][0][j][i]=((((ntemp+(i*5))+((j*5)*5))+5)-1);
				idel[k][1][j][i]=((ntemp+(i*5))+((j*5)*5));
				idel[k][2][j][i]=(((ntemp+(i*1))+((j*5)*5))+(5*(5-1)));
				idel[k][3][j][i]=((ntemp+(i*1))+((j*5)*5));
				idel[k][4][j][i]=(((ntemp+(i*1))+(j*5))+((5*5)*(5-1)));
				idel[k][5][j][i]=((ntemp+(i*1))+(j*5));
			}
		}
	}
	#pragma cetus private(col, col_0, col_1, i, i_0, i_1, i_10, i_11, i_12, i_2, i_3, i_4, i_5, i_6, i_7, i_8, i_9, ie, iface, ig, ig1, ig2, ig3, ig4, ije1, ije2, il, il1, il2, il3, il4, j, nnje, tmp, x, y, z) 
	#pragma loop name main#3 
	#pragma cetus parallel 
	#pragma omp parallel for if(((-1+nelt)<=8799)) private(col, col_0, col_1, i, i_0, i_1, i_10, i_11, i_12, i_2, i_3, i_4, i_5, i_6, i_7, i_8, i_9, ie, iface, ig, ig1, ig2, ig3, ig4, ije1, ije2, il, il1, il2, il3, il4, j, nnje, tmp, x, y, z)
	for (ie=0; ie<nelt; ie ++ )
	{
		#pragma cetus private(col, col_0, col_1, i, i_0, i_1, i_10, i_11, i_12, i_2, i_3, i_4, i_5, i_6, i_7, i_8, i_9, iface, ig, ig1, ig2, ig3, ig4, ije1, ije2, il, il1, il2, il3, il4, j, nnje, x, y, z) 
		#pragma cetus lastprivate(tmp) 
		#pragma loop name main#3#0 
		for (iface=0; iface<6; iface ++ )
		{
			/* get the collocation point index of the four local corners on the */
			/* face iface of element ie */
			il1=idel[ie][iface][0][0];
			il2=idel[ie][iface][0][5-1];
			il3=idel[ie][iface][5-1][0];
			il4=idel[ie][iface][5-1][5-1];
			/* get the mortar indices of the four local corners */
			ig1=idmo[ie][iface][0][0][0][0];
			ig2=idmo[ie][iface][1][0][0][5-1];
			ig3=idmo[ie][iface][0][1][5-1][0];
			ig4=idmo[ie][iface][1][1][5-1][5-1];
			/* copy the value from tmor to tx for these four local corners */
			tx[il1]=tmor[ig1];
			tx[il2]=tmor[ig2];
			tx[il3]=tmor[ig3];
			tx[il4]=tmor[ig4];
			/* nnje=1 for conforming faces, nnje=2 for nonconforming faces */
			if (cbc[ie][iface]==3)
			{
				nnje=2;
			}
			else
			{
				nnje=1;
			}
			/* for nonconforming faces */
			if (nnje==2)
			{
				/* nonconforming faces have four pieces of mortar, first map them to */
				/* two intermediate mortars, stored in tmp */
				/* r_init((double)tmp, LX1*LX1*2, 0.0); */
				#pragma cetus private(x, y, z) 
				#pragma loop name main#3#0#0 
				for (x=0; x<nnje; x ++ )
				{
					#pragma cetus private(y, z) 
					#pragma loop name main#3#0#0#0 
					for (y=0; y<5; y ++ )
					{
						#pragma cetus private(z) 
						#pragma loop name main#3#0#0#0#0 
						for (z=0; z<5; z ++ )
						{
							tmp[x][y][z]=0.0;
						}
					}
				}
				#pragma cetus firstprivate(tmp) 
				#pragma cetus private(col, i, i_0, ig, ije1, ije2, il, j) 
				#pragma cetus lastprivate(tmp) 
				#pragma loop name main#3#0#1 
				for (ije1=0; ije1<nnje; ije1 ++ )
				{
					#pragma cetus firstprivate(tmp) 
					#pragma cetus private(col, i, i_0, ig, ije2, il, j) 
					#pragma cetus lastprivate(tmp) 
					#pragma loop name main#3#0#1#0 
					for (ije2=0; ije2<nnje; ije2 ++ )
					{
						#pragma cetus private(col, i, i_0, ig, il, j) 
						#pragma loop name main#3#0#1#0#0 
						for (col=0; col<5; col ++ )
						{
							/* in each row col, when coloumn i=1 or LX1, the value */
							/* in tmor is copied to tmp */
							i=v_end[ije2];
							ig=idmo[ie][iface][ije2][ije1][col][i];
							tmp[ije1][col][i]=tmor[ig];
							/* in each row col, value in the interior three collocation */
							/* points is computed by apply mapping matrix qbnew to tmor */
							/* Normalized Loop */
							#pragma cetus private(ig, il, j) 
							#pragma cetus lastprivate(i_0) 
							#pragma loop name main#3#0#1#0#0#0 
							/* #pragma cetus reduction(+: tmp[ije1][col][(1+i_0)])  */
							for (i_0=0; i_0<=2; i_0 ++ )
							{
								il=idel[ie][iface][col][1+i_0];
								#pragma cetus private(ig, j) 
								#pragma loop name main#3#0#1#0#0#0#0 
								/* #pragma cetus reduction(+: tmp[ije1][col][(1+i_0)])  */
								for (j=0; j<5; j ++ )
								{
									ig=idmo[ie][iface][ije2][ije1][col][j];
									tmp[ije1][col][1+i_0]=(tmp[ije1][col][1+i_0]+(qbnew[ije2][j][(1+i_0)-1]*tmor[ig]));
								}
							}
							i=(1+i_0);
						}
					}
				}
				/* mapping from two pieces of intermediate mortar tmp to element */
				/* face tx */
				#pragma cetus private(col, col_0, i, i_1, i_2, i_3, ije1, il, j) 
				#pragma loop name main#3#0#2 
				/* #pragma cetus reduction(+: tx[il])  */
				for (ije1=0; ije1<nnje; ije1 ++ )
				{
					/* the first column, col=0, is an edge of face iface. */
					/* the value on the three interior collocation points, tx, is */
					/* computed by applying mapping matrices qbnew to tmp. */
					/* the mapping result is divided by 2, because there will be */
					/* duplicated contribution from another face sharing this edge. */
					col=0;
					/* Normalized Loop */
					#pragma cetus private(il, j) 
					#pragma cetus lastprivate(i_1) 
					#pragma loop name main#3#0#2#0 
					/* #pragma cetus reduction(+: tx[il])  */
					for (i_1=0; i_1<=2; i_1 ++ )
					{
						il=idel[ie][iface][1+i_1][col];
						#pragma cetus private(j) 
						#pragma loop name main#3#0#2#0#0 
						/* #pragma cetus reduction(+: tx[il])  */
						for (j=0; j<5; j ++ )
						{
							tx[il]=(tx[il]+((qbnew[ije1][j][(1+i_1)-1]*tmp[ije1][j][col])*0.5));
						}
					}
					i=(1+i_1);
					/* for column 1 ~ lx-2 */
					/* Normalized Loop */
					#pragma cetus private(i, i_2, il, j) 
					#pragma cetus lastprivate(col_0) 
					#pragma loop name main#3#0#2#1 
					/* #pragma cetus reduction(+: tx[il])  */
					for (col_0=0; col_0<=2; col_0 ++ )
					{
						/* when i=0 or LX1-1, the collocation points are also on an edge of */
						/* the face, so the mapping result also needs to be divided by 2 */
						i=v_end[ije1];
						il=idel[ie][iface][i][1+col_0];
						tx[il]=(tx[il]+(tmp[ije1][i][1+col_0]*0.5));
						/* compute the value at interior collocation points in */
						/* columns 1 ~ LX1-1 */
						/* Normalized Loop */
						#pragma cetus private(il, j) 
						#pragma cetus lastprivate(i_2) 
						#pragma loop name main#3#0#2#1#0 
						/* #pragma cetus reduction(+: tx[il])  */
						for (i_2=0; i_2<=2; i_2 ++ )
						{
							il=idel[ie][iface][1+i_2][1+col_0];
							#pragma cetus private(j) 
							#pragma loop name main#3#0#2#1#0#0 
							/* #pragma cetus reduction(+: tx[il])  */
							for (j=0; j<5; j ++ )
							{
								tx[il]=(tx[il]+(qbnew[ije1][j][(1+i_2)-1]*tmp[ije1][j][1+col_0]));
							}
						}
						i=(1+i_2);
					}
					col=(1+col_0);
					/* same as col=0 */
					col=(5-1);
					/* Normalized Loop */
					#pragma cetus private(il, j) 
					#pragma cetus lastprivate(i_3) 
					#pragma loop name main#3#0#2#2 
					/* #pragma cetus reduction(+: tx[il])  */
					for (i_3=0; i_3<=2; i_3 ++ )
					{
						il=idel[ie][iface][1+i_3][col];
						#pragma cetus private(j) 
						#pragma loop name main#3#0#2#2#0 
						/* #pragma cetus reduction(+: tx[il])  */
						for (j=0; j<5; j ++ )
						{
							tx[il]=(tx[il]+((qbnew[ije1][j][(1+i_3)-1]*tmp[ije1][j][col])*0.5));
						}
					}
					i=(1+i_3);
				}
				/* for conforming faces */
			}
			else
			{
				/* face interior */
				/* Normalized Loop */
				#pragma cetus private(i, i_4, ig, il) 
				#pragma cetus lastprivate(col_1) 
				#pragma loop name main#3#0#3 
				for (col_1=0; col_1<=2; col_1 ++ )
				{
					/* Normalized Loop */
					#pragma cetus private(ig, il) 
					#pragma cetus lastprivate(i_4) 
					#pragma loop name main#3#0#3#0 
					for (i_4=0; i_4<=2; i_4 ++ )
					{
						il=idel[ie][iface][1+col_1][1+i_4];
						ig=idmo[ie][iface][0][0][1+col_1][1+i_4];
						tx[il]=tmor[ig];
					}
					i=(1+i_4);
				}
				col=(1+col_1);
				/* edges of conforming faces */
				/* if local edge 0 is a nonconforming edge */
				if (idmo[ie][iface][0][0][0][5-1]!=( - 1))
				{
					/* Normalized Loop */
					#pragma cetus private(ig, ije1, il, j) 
					#pragma cetus lastprivate(i_5) 
					#pragma loop name main#3#0#4 
					/* #pragma cetus reduction(+: tx[il])  */
					for (i_5=0; i_5<=2; i_5 ++ )
					{
						il=idel[ie][iface][0][1+i_5];
						#pragma cetus private(ig, ije1, j) 
						#pragma loop name main#3#0#4#0 
						/* #pragma cetus reduction(+: tx[il])  */
						for (ije1=0; ije1<2; ije1 ++ )
						{
							#pragma cetus private(ig, j) 
							#pragma loop name main#3#0#4#0#0 
							/* #pragma cetus reduction(+: tx[il])  */
							for (j=0; j<5; j ++ )
							{
								ig=idmo[ie][iface][ije1][0][0][j];
								tx[il]=(tx[il]+((qbnew[ije1][j][(1+i_5)-1]*tmor[ig])*0.5));
							}
						}
					}
					i=(1+i_5);
					/* if local edge 0 is a conforming edge */
				}
				else
				{
					/* Normalized Loop */
					#pragma cetus private(ig, il) 
					#pragma cetus lastprivate(i_6) 
					#pragma loop name main#3#0#5 
					for (i_6=0; i_6<=2; i_6 ++ )
					{
						il=idel[ie][iface][0][1+i_6];
						ig=idmo[ie][iface][0][0][0][1+i_6];
						tx[il]=tmor[ig];
					}
					i=(1+i_6);
				}
				/* if local edge 1 is a nonconforming edge */
				if (idmo[ie][iface][1][0][1][5-1]!=( - 1))
				{
					/* Normalized Loop */
					#pragma cetus private(ig, ije1, il, j) 
					#pragma cetus lastprivate(i_7) 
					#pragma loop name main#3#0#6 
					/* #pragma cetus reduction(+: tx[il])  */
					for (i_7=0; i_7<=2; i_7 ++ )
					{
						il=idel[ie][iface][1+i_7][5-1];
						#pragma cetus private(ig, ije1, j) 
						#pragma loop name main#3#0#6#0 
						/* #pragma cetus reduction(+: tx[il])  */
						for (ije1=0; ije1<2; ije1 ++ )
						{
							#pragma cetus private(ig, j) 
							#pragma loop name main#3#0#6#0#0 
							/* #pragma cetus reduction(+: tx[il])  */
							for (j=0; j<5; j ++ )
							{
								ig=idmo[ie][iface][1][ije1][j][5-1];
								tx[il]=(tx[il]+((qbnew[ije1][j][(1+i_7)-1]*tmor[ig])*0.5));
							}
						}
					}
					i=(1+i_7);
					/* if local edge 1 is a conforming edge */
				}
				else
				{
					/* Normalized Loop */
					#pragma cetus private(ig, il) 
					#pragma cetus lastprivate(i_8) 
					#pragma loop name main#3#0#7 
					for (i_8=0; i_8<=2; i_8 ++ )
					{
						il=idel[ie][iface][1+i_8][5-1];
						ig=idmo[ie][iface][0][0][1+i_8][5-1];
						tx[il]=tmor[ig];
					}
					i=(1+i_8);
				}
				/* if local edge 2 is a nonconforming edge */
				if (idmo[ie][iface][0][1][5-1][1]!=( - 1))
				{
					/* Normalized Loop */
					#pragma cetus private(ig, ije1, il, j) 
					#pragma cetus lastprivate(i_9) 
					#pragma loop name main#3#0#8 
					/* #pragma cetus reduction(+: tx[il])  */
					for (i_9=0; i_9<=2; i_9 ++ )
					{
						il=idel[ie][iface][5-1][1+i_9];
						#pragma cetus private(ig, ije1, j) 
						#pragma loop name main#3#0#8#0 
						/* #pragma cetus reduction(+: tx[il])  */
						for (ije1=0; ije1<2; ije1 ++ )
						{
							#pragma cetus private(ig, j) 
							#pragma loop name main#3#0#8#0#0 
							/* #pragma cetus reduction(+: tx[il])  */
							for (j=0; j<5; j ++ )
							{
								ig=idmo[ie][iface][ije1][1][5-1][j];
								tx[il]=(tx[il]+((qbnew[ije1][j][(1+i_9)-1]*tmor[ig])*0.5));
							}
						}
					}
					i=(1+i_9);
					/* if local edge 2 is a conforming edge */
				}
				else
				{
					/* Normalized Loop */
					#pragma cetus private(ig, il) 
					#pragma cetus lastprivate(i_10) 
					#pragma loop name main#3#0#9 
					for (i_10=0; i_10<=2; i_10 ++ )
					{
						il=idel[ie][iface][5-1][1+i_10];
						ig=idmo[ie][iface][0][0][5-1][1+i_10];
						tx[il]=tmor[ig];
					}
					i=(1+i_10);
				}
				/* if local edge 3 is a nonconforming edge */
				if (idmo[ie][iface][0][0][5-1][0]!=( - 1))
				{
					/* Normalized Loop */
					#pragma cetus private(ig, ije1, il, j) 
					#pragma cetus lastprivate(i_11) 
					#pragma loop name main#3#0#10 
					/* #pragma cetus reduction(+: tx[il])  */
					for (i_11=0; i_11<=2; i_11 ++ )
					{
						il=idel[ie][iface][1+i_11][0];
						#pragma cetus private(ig, ije1, j) 
						#pragma loop name main#3#0#10#0 
						/* #pragma cetus reduction(+: tx[il])  */
						for (ije1=0; ije1<2; ije1 ++ )
						{
							#pragma cetus private(ig, j) 
							#pragma loop name main#3#0#10#0#0 
							/* #pragma cetus reduction(+: tx[il])  */
							for (j=0; j<5; j ++ )
							{
								ig=idmo[ie][iface][0][ije1][j][0];
								tx[il]=(tx[il]+((qbnew[ije1][j][(1+i_11)-1]*tmor[ig])*0.5));
							}
						}
					}
					i=(1+i_11);
					/* if local edge 3 is a conforming edge */
				}
				else
				{
					/* Normalized Loop */
					#pragma cetus private(ig, il) 
					#pragma cetus lastprivate(i_12) 
					#pragma loop name main#3#0#11 
					for (i_12=0; i_12<=2; i_12 ++ )
					{
						il=idel[ie][iface][1+i_12][0];
						ig=idmo[ie][iface][0][0][1+i_12][0];
						tx[il]=tmor[ig];
					}
					i=(1+i_12);
				}
			}
		}
	}
	_ret_val_0=0;
	return _ret_val_0;
}

void r_init(double a[], int n, double _const)
{
	int i;
	#pragma cetus private(i) 
	#pragma loop name r_init#0 
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<(1L+(3L*n)))) private(i)
	for (i=0; i<n; i ++ )
	{
		a[i]=_const;
	}
	return ;
}
