void* processFunc(void *arg) {
	int tid = (int *) arg;
	sleep(rand()%10);
	pthread_mutex_lock(&lock);
		int pid = allocate_pid();
		if(pid == -1) {
			printf("\nThread %d : Unable to allocate pid! All PIDs in use.\n", tid);
			pthread_mutex_unlock(&lock);
			pthread_exit(NULL);
		}
	pthread_mutex_unlock(&lock);

	printf("\nThread %d : Allocated PID %d", tid, pid);
	printf("\nThread %d : Running code...", tid);
	sleep(rand()%10+1);
	printf("\nThread %d : Code Completed", tid);

	pthread_mutex_lock(&lock);
		printf("\nThread %d : Releasing allocated PID %d", tid, pid);
		release_pid(pid);	
		printf("\nThread %d : PID %d Released", tid, pid);
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}

