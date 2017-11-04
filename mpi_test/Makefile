HELLO=mpi_hello
SR=mpi_send_recv
MPICC?=mpicc

all: ${HELLO} ${SR}

${HELLO}: mpi_hello.c    ;   ${MPICC} -o $@ $^
${SR}: mpi_send_recv.c    ;   ${MPICC} -o $@ $^

clean:  ;   rm ${HELLO} ${SR}

