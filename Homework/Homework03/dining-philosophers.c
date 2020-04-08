#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
#define EAT_TIME 2

int philosophers[N] = {0,1,2,3,4};
char *philosopher_names[N] = {"Plato", "Aristotle", "Socrates", "Descartes", "Nietzsche"};
int forks[N] = {0,1,2,3,4};

int check = 0;

pthread_t philosopher_threads[N];

static pthread_mutex_t forks_mutex[N] = {
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER
};
//= {pthread_mutex_t forks_mutex0, pthread_mutex_t forks_mutex1, pthread_mutex_t forks_mutex2, pthread_mutex_t forks_mutex3, pthread_mutex_t forks_mutex4};

int remaining = N;

// order:

//                  Plato

//         4                     0

//    Nietzsche               Aristotle

//        3                       1
 
//     Descartes              Socrates

//                     2

struct philosopher {
	char* name;
	int id;
	int left_fork;
	int right_fork;
	pthread_mutex_t* left_fork_mutex;
	pthread_mutex_t* right_fork_mutex;

	int has_eaten;
};

struct philosopher p[N];

void* eat(void* input) {
	int *n = (int *)input;
	int pid = *n;
	while (1) {
		if (p[pid].has_eaten == 0) {
			pthread_mutex_lock (p[pid].left_fork_mutex);
			int err = pthread_mutex_trylock (p[pid].right_fork_mutex);
			if (!err) {
				printf ("\n%s grabbed fork %d and fork %d.\n", p[pid].name, p[pid].right_fork, p[pid].left_fork);
				printf("%s is eating.\n", p[pid].name);
				sleep (EAT_TIME);
				p[pid].has_eaten = 1;
				check ++;
				pthread_mutex_unlock(p[pid].right_fork_mutex);
			} 
			pthread_mutex_unlock(p[pid].left_fork_mutex);
		}
		if (check == N) {
			break;
		}
	}
	return 0;
}

int main (void) {
	//create philosopher structs


	for (int i = 0; i < N; i++) {
		p[i].name = philosopher_names[i];
		p[i].id = philosophers[i];
		p[i].has_eaten = 0;
		p[i].left_fork = forks[i];
		if (p[i].id != 0) {
			p[i].right_fork = forks[i-1];
		} else {
			p[i].right_fork = forks[N-1];
		}
		p[i].left_fork_mutex = &forks_mutex[p[i].left_fork];
		p[i].right_fork_mutex = &forks_mutex[p[i].right_fork];

		//printf ("\n Philosopher %d File: \n Name: %s \n Right Fork: %d \n Left Fork: %d \n", p[i].id, p[i].name, p[i].right_fork, p[i].left_fork);
	}

	//create philosopher threads


	for (int i = 0; i < N; i++) {
		pthread_create(&philosopher_threads[i], NULL, eat, (void *)&p[i].id);
	}

	//join philosopher threads

	for (int i = 0; i < N; i++) {
		pthread_join(philosopher_threads[i], NULL);
	}

	return 0;
}