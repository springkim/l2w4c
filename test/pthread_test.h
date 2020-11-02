#pragma once
#include<stdio.h>
#include<pthread.h>
inline void func_pthread_cleanup(void* arg) {
	printf("Thread clean up\n");
	free(arg);
}
inline void* func_pthread(void* ptr) {
	int ret = 0;
	size_t type = (size_t)ptr;
	void* block = malloc(100);
	pthread_cleanup_push(func_pthread_cleanup, block);
	int b = rand() % 2;
	for (int i = 0; i<10; i++) {
		if (b && i == 5) {
			pthread_exit(&ret);
		}
		printf("Thread %zd\n", type);
	}
	pthread_cleanup_pop(0);
	return NULL;
}
int pthread_test() {
#define N 10
	pthread_t th[N];
	int thv[N];
	for (int i = 0; i < N; i++) {
		thv[i] = i;
		pthread_create(&th[i], NULL, func_pthread, (void*)thv[i]);
	}

	for (int i = 0; i < N; i++) {
		pthread_join(th[i], NULL);
	}
	return 0;
}