#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "boxtest.h"
#include "idtest.h"

int main (int argc, char* argv[]) {
    srand(time(NULL));

    printf("Launching tests...\n");

    id_test();
    box_test();

    printf("All tests passed!\n");

    return 0;
}
