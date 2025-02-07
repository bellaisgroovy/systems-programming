#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct town {
    int population;
} town_t;

typedef struct _move {
    town_t * oldTown;
    town_t * newTown;
} move_t;

pthread_mutex_t reaper;

void * birth(void * townArg) {
    pthread_mutex_lock(&reaper);

    // We need to get the town out of the argument.
    town_t * town = (town_t *)townArg;
    int currPopulation = town->population;
    currPopulation++;

    printf("Population of this town was %d, but is now %d.\n",
           town->population,
           currPopulation);

    town->population = currPopulation;

    pthread_mutex_unlock(&reaper);
    pthread_exit(NULL);
}

void * death(void * townArg) {
    pthread_mutex_lock(&reaper);

    // We need to get the town out of the argument.
    town_t * town = (town_t *)townArg;
    int currPopulation = town->population;
    currPopulation--;

    printf("Population of this town was %d, but is now %d.\n",
           town->population,
           currPopulation);

    town->population = currPopulation;

    pthread_mutex_unlock(&reaper);
    pthread_exit(NULL);
} 

int main() {
    pthread_mutex_init(&reaper, NULL);

    town_t falkirk = {750};
    town_t glasgow = {1500};
    town_t stirling = {900};

    move_t ftos = {&falkirk, &stirling};
    move_t gtos = {&glasgow, &stirling};
    move_t stof = {&stirling, &falkirk};

    pthread_t actions[10];
    pthread_create(&actions[0], NULL, birth, &falkirk);
    pthread_create(&actions[1], NULL, death, &falkirk);
    pthread_create(&actions[2], NULL, birth, &falkirk);
    pthread_create(&actions[3], NULL, birth, &stirling);
    pthread_create(&actions[4], NULL, birth, &glasgow);
    pthread_create(&actions[5], NULL, death, &glasgow);
    pthread_create(&actions[6], NULL, death, &glasgow);

    int i;
    for (i = 0; i < 7; i++) { // remember to change this when you implement the moves!
        pthread_join(actions[i], NULL);
    }

    printf("\nFalkirk's final population is %d.\nStirling's final population is %d.\nGlasgow's final population is %d.\n\n",
           falkirk.population,
           stirling.population,
           glasgow.population);

    return 0;
}
