#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "idtest.h"
#include "id.h"

void id_test() {
    printf("id.c tests...\n");

    for (int i = 0; i < 10000; i++) {
        char* id = id_new();

        for(int character = 0; i < IDLEN; i++) {
            assert("Should contain only characters between A-Z" && id[character] >= 'A' && id[character] <= 'Z');
        }

        free(id);
    }

    for (int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {

        }
    }

    printf("id.c tests passed!\n");
}
