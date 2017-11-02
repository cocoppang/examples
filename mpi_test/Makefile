EXECS=mpi_test
MPICC?=mpicc

all: ${EXECS}

mpi_test: mpi_test.c    ;   ${MPICC} -o $@ $^

clean:  ;   rm ${EXECS}

