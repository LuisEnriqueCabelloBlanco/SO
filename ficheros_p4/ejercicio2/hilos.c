#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct data{
	int tNum;
	char priority;
};

void *thread_usuario(void *arg)
{
	struct data* mData = arg;
	
	pthread_t id = pthread_self();
	char prio = mData->priority;
	int tNum = mData->tNum;
	
	free(mData);
	printf("[Hilo %ld] num:%d priority %s\n",id,tNum,&prio);
}

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);

	struct data** threads;
	
	threads = calloc(n,sizeof(**threads));
	
	pthread_t id;

	for(int i=0;i<n;i++){

		threads[i] = malloc(sizeof(*threads));
		threads[i]->tNum=i;
		threads[i]->priority = ((i%2 ==0) ? 'P':'N');
		if(pthread_create(&id,NULL,thread_usuario,threads[i])!=0){
			printf("Error creating thread ocurred");
			exit(EXIT_FAILURE);
		}
	}
	//pthread_join(threads[0],&res);

	free(threads);
	return 0;
}
