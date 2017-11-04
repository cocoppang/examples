THREAD=thread
BARRIER=thread_barrier
CC=g++
LIBS=-lpthread -std=c++11

all: ${THREAD} ${BARRIER}

$(THREAD): $(THREAD).cpp    ;   ${CC} -o $@ $^ ${LIBS}
$(BARRIER): $(BARRIER).cpp    ;   ${CC} -o $@ $^ ${LIBS}

clean:  ;   rm ${THREAD} ${BARRIER}

