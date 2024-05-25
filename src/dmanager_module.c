#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
int compare_door(const void *a, const void *b);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
    qsort(doors, DOORS_COUNT, sizeof(struct door), compare_door);
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

int compare_door(const void *a, const void *b) {
    const struct door *door1 = (const struct door *)a;
    const struct door *door2 = (const struct door *)b;
    return door1->id - door2->id;
}