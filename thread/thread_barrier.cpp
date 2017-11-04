#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

using namespace std;

pthread_barrier_t mybarrier;

void* thread_func(void *t_id){
    int thread_id = *(int*)t_id;
    int wait_sec = 1 + rand() % 5;
    cout << "thread " << thread_id << ": Wait for " << wait_sec << " seconds" << endl;
    sleep(wait_sec);
    cout << "thread " << thread_id << " I'm ready..." << endl;

    pthread_barrier_wait(&mybarrier);

    cout << "thread " << thread_id << " going!" << endl;
    return NULL;
}

int main(){
    pthread_t thread[NUM_THREADS];
    int id[NUM_THREADS];

    srand(time(NULL));
    pthread_barrier_init(&mybarrier, NULL, NUM_THREADS);

    for(int i = 0; i < NUM_THREADS;i++)
    {
	id[i] = i;
	pthread_create(&thread[i], NULL, thread_func, &id[i]);
    }

//    cout << " main() is ready" << endl;
//
//    pthread_barrier_wait(&mybarrier);
//
//    cout << "main() is going" << endl;

    for(int i = 0 ; i < NUM_THREADS;i++)
    {
	pthread_join(thread[i], NULL);
    }

    pthread_barrier_destroy(&mybarrier);

    return 0;
}
