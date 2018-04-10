int main(int argc, char** arv) {
	allocate_map(MAX);
	int nThreads;
	printf("\nHow many threads? ");
	scanf("%d", &nThreads);

	pthread_t threads[nThreads];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	for(int i=0; i<nThreads; i++)
		pthread_create(&threads[i], &attr, processFunc, (void *)i);

	for(int i=0; i<nThreads; i++)
		pthread_join(threads[i], NULL);

	printf("\nAll threads executed\n");

	return 0;
}
