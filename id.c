#include <stdlib.h>
#include "id.h"

char* id_new() {
    char* result = malloc(IDLEN * sizeof(char));

    for (int i = 0; i < IDLEN - 1; i++) {
        result[i] = 'A' + (rand() % 26);
    }

    result[IDLEN - 1] = '\0';

    return result;
}
