/* ========================================================================== */
/* === Demo/cholmod_demo ==================================================== */
/* ========================================================================== */

/* -----------------------------------------------------------------------------
 * CHOLMOD/Demo Module.  Copyright (C) 2005-2013, Timothy A. Davis
 * -------------------------------------------------------------------------- */

/* Read in a matrix from a file, and use CHOLMOD to solve Ax=b if A is
 * symmetric, or (AA'+beta*I)x=b otherwise.  The file format is a simple
 * triplet format, compatible with most files in the Matrix Market format.
 * See cholmod_read.c for more details.  The readhb.f program reads a
 * Harwell/Boeing matrix (excluding element-types) and converts it into the
 * form needed by this program.  reade.f reads a matrix in Harwell/Boeing
 * finite-element form.
 *
 * Usage:
 *	cholmod_demo matrixfile
 *	cholmod_demo < matrixfile
 *
 * The matrix is assumed to be positive definite (a supernodal LL' or simplicial
 * LDL' factorization is used).
 *
 * Requires the Core, Cholesky, MatrixOps, and Check Modules.
 * Optionally uses the Partition and Supernodal Modules.
 * Does not use the Modify Module.
 *
 * See cholmod_simple.c for a simpler demo program.
 *
 * cholmod_demo is the same as cholmod_l_demo, except for the size of the
 * basic integer (int vs SuiteSparse_long)
 */

#include "cholmod_demo.h"
#include <sys/time.h>	// for gettimeofday()
#define NTRIALS 100

/* ff is a global variable so that it can be closed by my_handler */
FILE *ff ;

/* halt if an error occurs */
static void my_handler (int status, const char *file, int line,
    const char *message)
{
    printf ("cholmod error: file: %s line: %d status: %d: %s\n",
	    file, line, status, message) ;
    if (status < 0)
    {
	if (ff != NULL) fclose (ff) ;
	exit (0) ;
    }
}

int main (int argc, char **argv)
{
    double resid [4], t, ta, tf, ts [3], tot, bnorm, xnorm, anorm, rnorm, fl,
        anz, axbnorm, rnorm2, resid2, rcond ;
    FILE *f ;
    cholmod_sparse *A ;
    cholmod_dense *B, *W ;
    double one [2], zero [2], minusone [2], beta [2], xlnz ;
    cholmod_common Common, *cm ;
    double *Bx, *Rx, *Xx ;
    int i, n, isize, xsize, ordering, xtype, s, ss, lnz ;
    int trial, method, L_is_super ;
    struct timeval start, end;


    ts[0] = 0.;
    ts[1] = 0.;
    ts[2] = 0.;

    /* ---------------------------------------------------------------------- */
    /* get the file containing the input matrix */
    /* ---------------------------------------------------------------------- */

    ff = NULL ;
    if (argc > 1)
    {
	if ((f = fopen (argv [1], "r")) == NULL)
	{
	    my_handler (CHOLMOD_INVALID, __FILE__, __LINE__,
		    "unable to open file") ;
	}
	ff = f ;
    }
    else
    {
	f = stdin ;
    }

    /* ---------------------------------------------------------------------- */
    /* start CHOLMOD and set parameters */
    /* ---------------------------------------------------------------------- */

    cm = &Common ;
    cholmod_start (cm) ;
    CHOLMOD_FUNCTION_DEFAULTS ;     /* just for testing (not required) */

    /* use default parameter settings, except for the error handler.  This
     * demo program terminates if an error occurs (out of memory, not positive
     * definite, ...).  It makes the demo program simpler (no need to check
     * CHOLMOD error conditions).  This non-default parameter setting has no
     * effect on performance. */
    cm->error_handler = my_handler ;

    /* Note that CHOLMOD will do a supernodal LL' or a simplicial LDL' by
     * default, automatically selecting the latter if flop/nnz(L) < 40. */

    /* ---------------------------------------------------------------------- */
    /* create basic scalars */
    /* ---------------------------------------------------------------------- */

    zero [0] = 0 ;
    zero [1] = 0 ;
    one [0] = 1 ;
    one [1] = 0 ;
    minusone [0] = -1 ;
    minusone [1] = 0 ;
    beta [0] = 1e-6 ;
    beta [1] = 0 ;

    /* ---------------------------------------------------------------------- */
    /* read in a matrix */
    /* ---------------------------------------------------------------------- */

    printf("Reading in the input Matrix...\n");
    A = cholmod_read_sparse (f, cm) ;
    if (ff != NULL)
    {
        fclose (ff) ;
        ff = NULL ;
    }
    xtype = A->xtype ;
    anorm = 1 ;

    if (A->nrow > A->ncol)
    {
	/* Transpose A so that A'A+beta*I will be factorized instead */
	cholmod_sparse *C = cholmod_transpose (A, 2, cm) ;
	cholmod_free_sparse (&A, cm) ;
	A = C ;
	printf ("transposing input matrix\n") ;
    }

    /* ---------------------------------------------------------------------- */
    /* create an arbitrary right-hand-side */
    /* ---------------------------------------------------------------------- */

    n = A->nrow ;
    B = cholmod_zeros (n, 1, xtype, cm) ;
    Bx = B->x ;

#if GHS
    {
	/* b = A*ones(n,1), used by Gould, Hu, and Scott in their experiments */
	cholmod_dense *X0 ;
	X0 = cholmod_ones (A->ncol, 1, xtype, cm) ;
	cholmod_sdmult (A, 0, one, zero, X0, B, cm) ;
	cholmod_free_dense (&X0, cm) ;
    }
#else
    if (xtype == CHOLMOD_REAL)
    {
	/* real case */
	for (i = 0 ; i < n ; i++)
	{
	    double x = n ;
	    Bx [i] = 10000 + (i / x) ;
	}
    }
    else
    {
	/* complex case */
	for (i = 0 ; i < n ; i++)
	{
	    double x = n ;
	    Bx [2*i  ] = 1 + i / x ;		/* real part of B(i) */
	    Bx [2*i+1] = (x/2 - i) / (3*x) ;	/* imag part of B(i) */
	}
    }
#endif

    printf("Converting the input sparse matrix to dense format...\n");
    W = cholmod_sparse_to_dense(A, cm);
    
    printf("Reverting and Scaling the input sparse matrix...\n");

    A = cholmod_dense_to_sparse_scaling(W, TRUE, cm, B);

    cholmod_free_sparse (&A, cm) ;
    cholmod_free_dense (&B, cm) ;
    cholmod_finish (cm) ;
        
    
    return (0) ;
}
