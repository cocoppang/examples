#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#define NUM_THREADS 3
using namespace std;

std::queue<int> queues;
std::mutex mutexA;

int main()
{

	thread worker[NUM_THREADS];
	srandom(time(NULL)); 

	for(int i = 0 ; i < NUM_THREADS;i++)
	{
		worker[i] = thread([i](){
						while(1)
						{
							mutexA.lock();
							if(queues.size() >= 30)
							{
								mutexA.unlock();
								break;
							}
							queues.push(random() % 100);
							mutexA.unlock();
						}
					});
	}
	for(int i= 0;i < NUM_THREADS;i++)
	{
		worker[i].join();
	}
	while(1)
	{	
		if(queues.empty())
		{
			break;
		}
		cout << queues.front() << " ";
		queues.pop();
	}
	cout << endl;
	return 0;
}
