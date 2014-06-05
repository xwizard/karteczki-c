#include <stdio.h>
#include "boxtest.h"

int main (int argc, char* argv[]) {
    printf("Launching tests...\n");

    box_test();

    printf("Tests finished successfully!\n");

    return 0;
}
