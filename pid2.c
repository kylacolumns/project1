
#define MIN 10
#define MAX 1000

uint32_t *pid_map;
pthread_mutex_t lock;

int allocate_map(long long size) {
	pid_map = (uint32_t *)calloc(getBitmapSize(size), sizeof(uint32_t));
	if(pid_map == NULL)
		return -1;
	return 1;
}


int allocate_pid() {
	for(int i=MIN; i<MAX; i++) {
		if(get_bit(pid_map, i-1) == 0) {
			set_bit(pid_map, i-1);
			return i;
		}
	}
	return -1; // pid_map full
}

void release_pid(int pid) {

	clear_bit(pid_map, pid-1);
}

