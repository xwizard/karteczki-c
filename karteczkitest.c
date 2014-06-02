#include <stdio.h>
#include "boxtest.h"
#include "idtest.h"

int main (int argc, char* argv[]) {
    printf("Launching tests...\n");

    id_test();
    box_test();

    printf("Tests finished successfully!\n");

    return 0;
}
