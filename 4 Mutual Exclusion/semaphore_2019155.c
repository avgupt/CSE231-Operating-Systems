/* Avishi Gupta
   Roll no: 2019155*/

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct{
    int value;
    pthread_mutex_t mutex;
    pthread_cond_t  condition;
} my_semaphore;

void constructor(my_semaphore *my_semaphore, int n) {
    my_semaphore->value = n;
    pthread_mutex_init(&(my_semaphore->mutex), NULL);
    pthread_cond_init(&(my_semaphore->condition), NULL);  
}

void wait(my_semaphore *my_semaphore) {
    pthread_mutex_lock(&(my_semaphore->mutex));
    my_semaphore->value--;

    if (my_semaphore->value < 0) {
        // if semaphore not available, wait
        pthread_cond_wait(&(my_semaphore->condition), (&my_semaphore->mutex));
    }
    pthread_mutex_unlock(&(my_semaphore->mutex));
}

void signal(my_semaphore *my_semaphore) {
    pthread_mutex_lock(&(my_semaphore->mutex));
    my_semaphore->value++;
    if (my_semaphore->value <= 0) {
        pthread_cond_broadcast(&(my_semaphore->condition));
    }
    pthread_mutex_unlock(&(my_semaphore->mutex));
}

void printValue(my_semaphore *my_semaphore) {
    printf("Semaphore with value: %d", my_semaphore->value);
}

// ------------------------------------------------------------------------

#define k 5
#define EATING 0
#define HUNGRY 1
#define THINKING 2

#define TAKEN 0
#define AVAILABLE 1

int state[k];
int bowl[2];
int phil[k] = { 0, 1, 2, 3, 4 }; 

my_semaphore mutex;
my_semaphore s_bowl[2];
my_semaphore s_fork[k];

int left(int i) {
    return i;
}

int right(int i) {
    return (i + 1) % k;
}

void eat(int philNum) {
    if (state[philNum] == HUNGRY
    && state[left(philNum)] != EATING
    && state[right(philNum)] != EATING) {
        
        state[philNum] = EATING;
        printf("Philosopher %ld eats using forks %d and %d\n", pthread_self(), left(philNum), right(philNum));
        signal(&s_fork[philNum]);
    }
}

void pickFork(int philNum) {

    wait(&mutex);
    state[philNum] = HUNGRY;
    
    eat(philNum);

    signal(&mutex);
    wait(&s_fork[philNum]);
}

void pickBowls() {
    wait(&s_bowl[0]);
    bowl[0] = TAKEN;

    wait(&s_bowl[1]);
    bowl[1] = TAKEN;
}

void putFork(int philNum) {
    wait(&mutex);
    state[philNum] = THINKING;

    // printf("Philosopher %d is thinking\n", philNum + 1);

    eat(left(philNum));
    eat(right(philNum));

    signal(&mutex);
}

void putBowl() {
    signal(&s_bowl[0]);
    bowl[0] = AVAILABLE;

    signal(&s_bowl[1]);
    bowl[1] = AVAILABLE;
}

void startEating(int philNum) {
    pickFork(philNum);
    pickBowls();
}

void stopEating(int philNum) {
    putFork(philNum);
    putBowl();
}

void* feedPhilospher(void* n) {
    // printf("hello\n");
    while(1) {
        int* philNum = n;
        sleep(1);
        startEating(*philNum);
        stopEating(*philNum);
        sleep(1);
    }
}


int main() {
    // printf("hello\n");
    int N = k;
	pthread_t thread_id[k]; 

	constructor(&mutex, 1);
    constructor(&s_bowl[0], 1);
    constructor(&s_bowl[1], 1);

	for (int i = 0; i < N; i++) constructor(&s_fork[i], 0);

    while (1) {
        for (int i = 0; i < N; i++) { 
            pthread_create(&thread_id[i], NULL, 
                        feedPhilospher, &phil[i]);
            sleep(1);
        } 
    }

    for (int i = 0; i < N; i++) pthread_join(thread_id[i], NULL); 
  
    return 0;
}
   