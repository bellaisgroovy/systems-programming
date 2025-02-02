#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 3

typedef struct _movie {
    char title[50];
    int year_released;
    float rating;
} movie_t;

void * printFilm(void * arg) {
    movie_t * film = (movie_t *) arg;
    printf("%s (%d) has a metacritic score of %.2f\n",
           film->title,
           film->year_released,
           film->rating);
    pthread_exit(film);
}

int main() {

    movie_t films[NUM_THREADS] = {
        {"Fantastic Mr. Fox", 2009, 83},
        {"Grand Budapest Hotel", 2014, 88},
        {"Isle of Dogs", 2018, 82}
    };

    // Start NUM_THREADS threads which each run printFilm
    // passing in a pointer to a movie_t each time

    return 0;

}
