
CHECK=../Check

SRC=../Src

CFLAGS	= -O3

CC = gcc

C_LIB = -lm

CCOMPILE = $(CC) -c $(CFLAGS)

OBJS = cholmod_demo.o SuiteSparse_config.o $(SRC)/cholmod_symmetry.o $(CHECK)/cholmod_check.o \
	   $(CHECK)/cholmod_read.o $(CHECK)/cholmod_write.o $(SRC)/cholmod_dense.o \
	   $(SRC)/cholmod_sparse.o $(SRC)/cholmod_transpose.o $(SRC)/cholmod_common.o \
	   $(SRC)/cholmod_memory.o $(SRC)/cholmod_error.o $(SRC)/cholmod_triplet.o 


OBFILES = cholmod_demo.o cholmod_symmetry.o cholmod_check.o \
	   cholmod_read.o cholmod_write.o cholmod_dense.o \
	   cholmod_sparse.o cholmod_transpose.o cholmod_common.o \
	   cholmod_memory.o cholmod_error.o SuiteSparse_config.o cholmod_triplet.o 

exec: $(OBJS)
	${CC} ${CFLAGS} -o cholmod_demo ${OBFILES} -lm

.c.o:
	${CCOMPILE} $<

cholmod_demo.o:			cholmod_demo.c
SuiteSparse_config.o:	SuiteSparse_config.c
cholmod_check.o:  		$(CHECK)/cholmod_check.c
cholmod_read.o:	  		$(CHECK)/cholmod_read.c
cholmod_write.o:  		$(CHECK)/cholmod_write.c
cholmod_dense.o:		$(SRC)/cholmod_dense.c $(SRC)/t_cholmod_dense_scale.c
cholmod_sparse.o: 		$(SRC)/cholmod_sparse.c
cholmod_transpose.o:  	$(SRC)/cholmod_transpose.c $(SRC)/t_cholmod_transpose.c
cholmod_common.o:  		$(SRC)/cholmod_common.c
cholmod_memory.o:  		$(SRC)/cholmod_memory.c
cholmod_error.o:  		$(SRC)/cholmod_error.c
cholmod_triplet.o:		$(SRC)/cholmod_triplet.c $(SRC)/t_cholmod_triplet.c
cholmod_symmetry.o:		$(SRC)/cholmod_symmetry.c

clean:
	- rm -f *.o

